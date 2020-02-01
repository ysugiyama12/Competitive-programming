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
        ll n,d;
        // cin >> n >> d;
        n = rand() % 100;
        d = rand() % 100;
        // print(n,d);
        ll v = 0;
        for(ll i = 0; i * i <= d; i++){
            v = i;
        }
        ll tt = v-1 + (d + v-1) / v;

        // if(tt <= n){
        //     print("YES");
        // }else{
        //     print("NO");
        // }
        ll res = INF;
        for(ll i = 1; i < min(200000LL, n); i++){
            res = min(res, i-1 + (d + i-1) / i);
        }
        // if(res <= n){
        //     print("YES");
        // }else{
        //     print("NO");
        // }
        if(tt <= n && res <= n){
            print("YES");
        }else if(tt > n && res > n){
            print("NO");
        }else{
            print("え？");
        }
    }
    
 
}