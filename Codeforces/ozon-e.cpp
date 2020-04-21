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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll max_val = 0;
    ll val[5010] = {};
    rep(i,2,N){
        max_val += i/2;
        val[i] = i/2;
    }
    if(M > max_val){
        print(-1);
        return 0;
    }
    ll ans[5010] = {};
    ans[0] = 1; ans[1] = 2;
    rep(i,2,N){
        if(M == 0) break;
        if(M >= val[i]){
            ans[i] = i+1;
            M -= val[i];
            if(M == 0) break;
        }else{
            ll diff = val[i] - M;
            if(i % 2 == 0){
                ans[i] = i+1 + 2 * diff - 1;
            }else{
                ans[i] = i+1 + 2 * diff + 1;
            }
            break;
        }
    }
    ll mv = -1;
    rep(i,0,N){
        mv = max(mv, ans[i]);
    }
    mv++;
    ll idx = 0;
    rrep(i,N-1,0){
        if(ans[i] == 0){
            ans[i] = 999999999 - idx * mv;
            idx++;
        }
    }

    printa(ans, N);
    

}