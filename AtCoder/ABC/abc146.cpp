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
    ll A,B,X;
    cin >> A >> B >> X;
    ll ans = 0;
    rep(keta,1,15){
        ll diff = X - B * keta;
        if(diff < 0) continue;
        ll v = diff / A;
        ll min_val = pow(10, keta-1);
        ll max_val = min_val * 10 - 1;
        if(v >= min_val){
            ll res = min(v, max_val);
            ans = max(ans, res);
        }
    }
    // if(A * 1e9 + B * 10 <= X){
    //     ans = 1e9;
    // }
    print(ans);



    

}
