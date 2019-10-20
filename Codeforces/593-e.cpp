/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll a[100010];
    rep(i,0,M) cin >> a[i];
    ll ans = 0;
    bool ng[100010][2] = {};
    rep(i,0,M){
        a[i]--;
        if(a[i] - i - 1 >= 0){
            ng[a[i]-i-1][0] = true;
        }
        if(a[i] + i + 1 < N){
            ng[a[i]+i+1][1] = true;
        }
    }

    rep(i,0,N){
        ll lv = -1, rv = i;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            bool ok = true;
            if(i - mid > M+1){
                ok = false;
            }else if(i - mid < M+1){
                ok = true;
            }else{
                if(ng[i][1]){
                    ok = false;
                }
            }
            if(ok){
                rv = mid;
            }else{
                lv = mid;
            }
        }
        print(i, rv);
        ans += i - rv + 1;
        lv = i; rv = N;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            bool ok = true;
            if(mid - i > M+1){
                ok = false;
            }else if(mid - i < M+1){
                ok = true;
            }else{
                if(ng[i][0]) ok = false;
            }
            if(ok){
                lv = mid;
            }else{
                rv = mid;
            }
        }
        ans += lv - i + 1;
        ans--;
        print(i, lv);
    }
    print(ans);

    

}