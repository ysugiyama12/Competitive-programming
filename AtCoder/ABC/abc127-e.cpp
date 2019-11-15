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
struct Combination{
private:
    ll N;
    vector<ll> fac, facinv;

public:
    Combination(ll n){
        N = n;
        fac.push_back(1); fac.push_back(1);
        rep(i,2,N+1) fac.push_back(fac[i-1] * i % MOD);
        rep(i,0,N+1) facinv.push_back(power(fac[i], MOD-2));
    }
    ll power(ll x, ll n){
        if(n == 0) return 1LL;
        ll res = power(x * x % MOD, n/2);
        if(n % 2 == 1) res = res * x % MOD;
        return res;
    }
    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
    }
    ll npk(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[n-k] % MOD;
    }
    ll get(ll x){return fac[x];};
    ll getinv(ll x){return facinv[x];};
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,K;
    cin >> N >> M >> K;
    ll ans = 0;
    Combination cb(200010);
    rep(i,1,N){
        ll p = (N - i) * M % MOD * M % MOD * i % MOD;
        ll p2 = cb.nck(N*M-2, K-2);
        ans += p * p2 % MOD;
        ans %= MOD;
    }
    swap(N,M);
    rep(i,1,N){
        ll p = (N - i) * M % MOD * M % MOD * i % MOD;
        ll p2 = cb.nck(N*M-2, K-2);
        ans += p * p2 % MOD;
        ans %= MOD;
    }

    print(ans);
    

}