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
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll extgcd(ll a,ll b,ll &x,ll &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }

    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

vll divisor(ll M){
    vll div;
    for(ll i = 1; i * i <= M; i++){
        if(M % i == 0){
            div.push_back(i); if(i * i != M) div.push_back(M / i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}


void solve(){
    ll N;
    cin >> N;
    auto dd = divisor(2*N);
    ll ans = INF;
    for(auto &e: dd){
        ll e2 = 2 * N / e;
        if(gcd(e,e2) != 1 || e == 2*N) continue;
        ll x,y;
        extgcd(e, e2, x,y);
        x *= -1;
        x = (x % e2 + e2) % e2;
        ll k = e * x;
        chmin(ans, k); 

    }
    print(ans);

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}