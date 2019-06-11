#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
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
    Combination cb(200010);
    ll v1 = (N-1) * (3*N-5) % MOD;
    v1 *= cb.getinv(N) % MOD * cb.getinv(2) % MOD;
    v1 %= MOD;
    ll v2 = (M-1) * (3*M-5) % MOD;
    v2 *= cb.getinv(M) % MOD * cb.getinv(2) % MOD;
    v2 %= MOD;
    print2(v1,v2);
    ll ans = v1 * cb.nck(M*N, K) % MOD;
    ans += v2 * cb.nck(M*N,K) % MOD;
    ans %= MOD;
    print(ans);



}