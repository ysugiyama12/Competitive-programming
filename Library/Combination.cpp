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

struct Combination{
private:
    ll N;
public:
    vll fac, facinv, inv;

    Combination(ll n){
        N = n;
        fac.resize(N+1); facinv.resize(N+1); inv.resize(N+1);
        fac[0] = fac[1] = 1;
        facinv[0] = facinv[1] = 1;
        inv[1] = 1;
        rep(i,2,N+1){
            fac[i] = fac[i-1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            facinv[i] = facinv[i-1] * inv[i] % MOD;
        }
    }

    ll power(ll x, ll n, ll m = MOD){
        if(n == 0) return 1LL;
        ll res = power(x * x % m, n/2, m);
        if(n % 2 == 1) (res *= x) %= m;
        return res;
    }

    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        if(n < k) return 0LL;
        return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
    }
    
    ll npk(ll n, ll k){
        if(k == 0) return 1LL;
        if(n < k) return 0LL;
        return fac[n] * facinv[n-k] % MOD;
    }
};

struct Combination_pascal{
private:
    ll N;
public:
    vector<vll> dp;

    Combination_pascal(ll n){
        N = n;
        dp.assign(N+1, vll(N+1, -1));
        rep(i,0,N+1){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
    }

    ll calc(ll i, ll j){
        ll &res = dp[i][j];
        if(~res) return res;
        res = 0;
        res = calc(i-1, j-1) + calc(i-1, j);
        return res;
    }

    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        if(n < k) return 0LL;
        return calc(n,k);
    }
};
Combination cb(100010);

ll Starling(ll N, ll K){
    ll res = 0;
    rep(i,0,K+1){
        ll add = cb.nck(K,i) * cb.power(i, N) % MOD;
        if((K-i) % 2 == 0) res += add;
        else res -= add;
        res = (res + 2 * MOD) % MOD;
    }
    (res *= cb.facinv[K]) %= MOD;
    return res;
}

ll Bell(ll N, ll K) {
    if (K > N) K = N;
    vll jsum(K+2, 0);
    for (int j = 0; j <= K; ++j) {
        ll add = cb.facinv[j];
        if (j % 2 == 0) jsum[j+1] = jsum[j] + add;
        else jsum[j+1] = jsum[j] - add;
        jsum[j+1] = (jsum[j+1] + 2 * MOD) % MOD;
    }

    ll res = 0;
    for (int i = 0; i <= K; ++i) {
        res += cb.power(i,N) * cb.facinv[i] % MOD * jsum[K-i+1] % MOD;
        res %= MOD;
    }
    return res;
}

ll Partition(ll N, ll K){
    if(N < 0) return 0;
    if(N < K) K = N;
    vector<vll> dp(N+1, vll(N+1, 0));
    rep(i,0,N+1) dp[0][i] = 1;
    rep(n,1,N+1){
        rep(k,1,N+1){
            if(n - k < 0) dp[n][k] = dp[n][k-1];
            else dp[n][k] = dp[n][k-1] + dp[n-k][k];
            dp[n][k] %= MOD;
        }
    }
    return dp[N][K];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination cb(100010);
    
}