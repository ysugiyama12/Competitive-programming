/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
// verify: https://atcoder.jp/contests/abc186/submissions/23946605

ll ext_gcd(ll a,ll b,ll &x,ll &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }

    ll d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


void solve(){
    ll N,S,K;
    cin >> N >> S >> K;
    // Nx - Ky = S
    ll g = gcd(N, K);
    if(S % g != 0){
        print(-1);
        return;
    }
    ll x,y;
    ext_gcd(N,K,x,y);
    x *= S / g;
    y *= -S / g;
    y = (y%(N/g) + (N/g)) % (N/g);
    print(y);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
}