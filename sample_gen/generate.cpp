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
mt19937 mrand(random_device{}());

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T = 1000;
    print(T);
    while(T--){
        ll N = 2;
        cout << N << endl;
        rep(i,0,N){
            ll a = mrand() % 10, b = mrand() % 10;
            cout << a << " " << b << endl;
        }
    }

    

}