#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)

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
ll dp[1010][1010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination comb(100010);
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    dp[0][N] = 1;
    ll val[1010] = {};
    rep(i,0,1010){
        val[i] = comb.power(i,MOD-2);
    }
    rrep(q,N,0){
        rep(p,1,A){
            dp[p][q] += dp[p-1][q];
            dp[p][q] %= MOD;
        }
        rep(p,A,B+1){
            dp[p][q] += dp[p-1][q]; //一つも作らない
            dp[p][q] %= MOD;
            ll v = dp[p-1][q];
            for(int i = 1; i <= D && i <= q/p; i++){
                v *= (comb.nck(q-(i-1)*p, p) * val[i]) % MOD;
                v %= MOD;
                if(i >= C){
                    dp[p][q-i*p] += v;
                    dp[p][q-i*p] %= MOD;
                }
            }
        }
    }
    print(dp[B][0]);
    
}