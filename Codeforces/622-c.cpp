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
    ll N;
    cin >> N;
    ll m[1010];
    rep(i,0,N) cin >> m[i];
    ll ans[1010] = {};
    ll max_val = 0;
    rep(i,0,N){
        ll m2[1010];
        rep(j,0,N) m2[j] = m[j];
        rrep(j,i-1,0){
            m2[j] = min(m2[j], m2[j+1]);
        }
        rep(j,i+1,N){
            m2[j] = min(m2[j], m2[j-1]);
        }
        ll res = 0;
        rep(j,0,N) res += m2[j];
        if(res > max_val){
            rep(j,0,N) ans[j] = m2[j];
            max_val = res;
        }
    }
    printa(ans, N);
    

}