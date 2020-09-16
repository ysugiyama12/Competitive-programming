/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
#define Case(t) cout << "Case #" << t << ": "
mt19937 mrand(random_device{}());
ll aa,bb,cc;

void solve2(ll l, ll r){
    ll cur = 1;
    while(true){
        if(l < cur && r < cur) break;
        if(l >= r){
            l -= cur;
        }else{
            r -= cur;
        }
        cur++;
    }
    aa = cur-1; bb = l; cc=r;
    print(cur-1,l,r);
}

void solve(ll t){
    ll L,R;
    // cin >> L >> R;
    L = mrand() % 2000000000LL;
    R = mrand() % 2000000000LL;
    solve2(L,R);
    ll lv = 0, rv = 3e9;
    ll diff_init = L-R;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        ll sum = mid * (mid + 1) / 2;
        if(abs(sum) >= abs(diff_init)){
            rv = mid;
        }else{
            lv = mid;
        }
    }
    ll change_pos = rv;
    ll change_val = 0;
    if(diff_init > 0){
        change_val = diff_init - change_pos * (change_pos + 1) / 2;
    }else{
        change_val = diff_init + change_pos * (change_pos + 1) / 2;
    }
    if(diff_init == 0){
        change_pos = 0;
        change_val = 0;
    }

    lv = 0; rv = 3e9;

    while(rv - lv > 1){
        // midが可能か
        ll mid = (rv + lv) / 2;
        bool ok = true;
        ll sum = mid * (mid - 1) / 2;
        if(sum > L+R){
            ok = false;
        }else{
            ll diff = 0;
            if(mid-1 < change_pos){
                if(diff_init > 0){
                    diff = diff_init - mid * (mid-1) / 2;
                }else{
                    diff = diff_init + mid * (mid-1) / 2;
                }
            }else{
                ll ps = mid-1 - change_pos;
                if(ps % 2 == 0){
                    if(change_val >= 0){
                        diff = change_val + ps/2;
                    }else{
                        diff = change_val - ps/2;
                    }
                }else{
                    ps--;
                    if(change_val >= 0){
                        ll val = change_val - (change_pos+1);
                        diff = val - ps/2;
                    }else{
                        ll val = change_val + change_pos+1;
                        diff = val + ps/2;
                    }
                }
            }
            ll v1 = diff, v2 = L+R - sum;
            ll a = (v1+v2)/2;
            ll b = (v2-v1)/2;
            if(a >= mid || b >= mid){
            }else{
                ok = false;
            }
        }
        if(ok){
            lv = mid;
        }else{
            rv = mid;
        }
    }
    ll ans = lv;
    ll diff = 0;
    if(ans < change_pos){
        if(diff_init > 0){
            diff = diff_init - ans * (ans+1) / 2;
        }else{
            diff = diff_init + ans * (ans+1) / 2;
        }
    }else{
        ll ps = ans - change_pos;
        if(ps % 2 == 0){
            if(change_val >= 0){
                diff = change_val + ps/2;
            }else{
                diff = change_val - ps/2;
            }
        }else{
            ps--;
            if(change_val >= 0){
                ll val = change_val - (change_pos+1);
                diff = val - ps/2;
            }else{
                ll val = change_val + change_pos+1;
                diff = val + ps/2;
            }
        }
    }
    ll v1 = diff, v2 = L+R - ans * (ans+1)/2;
    ll a = (v1+v2)/2;
    ll b = (v2-v1)/2;
    
    Case(t);
    print(ans,a,b);
    if(aa != ans || bb != a || cc != b){
        print("Oops");
        print(L,R);
        exit(1);
    }

    

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    rep(i,1,t+1) solve(i);
}