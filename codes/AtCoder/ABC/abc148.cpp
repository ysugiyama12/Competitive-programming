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
    if(N % 2 == 1){
        print(0);
        return 0;
    }
    ll num2 = 0;
    ll n = 2;
    while(n <= N){
        num2 += N/n;
        n *= 2;
    }
    ll num5 = 0;
    n = 5;
    while(n <= N){
        ll v1 = (N/n)/2;
        num5 += v1;
        n *= 5;
    }
    ll ans = min(num2, num5);
    ll num10 = 0;
    n = 10;
    while(n <= N){
        ll v1 = (N/n);
        num10 += v1;
        n *= 10;
    }
    print(ans, num10);

    

}
