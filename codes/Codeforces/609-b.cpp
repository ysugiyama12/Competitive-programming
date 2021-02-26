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
    ll a[300010];
    rep(i,0,N) cin >> a[i];
    ll shiro = 0, kuro = 0;
    rep(i,0,N){
        if(i % 2 == 0){
            shiro += (a[i]+1) / 2;
            kuro += a[i]/2;
        }else{
            shiro += a[i]/2;
            kuro += (a[i]+1) / 2;
        }
    }
    if(shiro > kuro) swap(shiro, kuro);
    print(shiro);


     
    

}