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
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> a(N);
        rep(i,0,N) cin >> a[i];
        vector<ll> prev(N+1, -1);
        ll ans = INF;
        rep(i,0,N){
            if(prev[a[i]] == -1){
                prev[a[i]] = i;
            }else{
                ans = min(ans, i - prev[a[i]]);
                prev[a[i]] = i;
            }
        }
        if(ans == INF){
            print(-1);
        }else{
            print(ans+1);
        }

    }
    

}