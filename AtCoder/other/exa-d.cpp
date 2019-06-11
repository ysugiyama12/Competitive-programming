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
    ll N,X;
    cin >> N >> X;
    ll S[210];
    rep(i,0,N) cin >> S[i];
    ll dp[210][210] = {}; // iがj番目に取り除かれる確率
    Combination comb(100010);
    rep(i,0,N){
        dp[i][0] = X;
    }
    rep(i,0,N){
        dp[i][1] = X%S[i];
    }
    rep(i,0,N){
        rep(j,2,N+1){
            rep(k,0,N){
                if(i == k) continue;
                dp[i][j] += comb.get(j-1) * (dp[k][j-1] % S[k]);
                dp[i][j] %= MOD;
            }
        }
    }
    ll ans = 0;
    rep(i,0,N){
        ans += dp[i][N] % MOD;
        ans %= MOD;
    }
    print(ans);
    
}