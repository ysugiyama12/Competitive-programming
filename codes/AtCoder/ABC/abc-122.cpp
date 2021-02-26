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
char c(ll x){
    if(x == 0) return 'T';
    if(x == 1) return 'A';
    if(x == 2) return 'G';
    return 'C';
}

bool check(ll t, ll j, ll k, ll l){
    if(c(k) == 'A' && c(j) == 'G' && c(t) == 'C'){
        return false;
    }else if(c(k) == 'G' && c(j) == 'A' && c(t) == 'C'){
        return false;
    }else if(c(k) == 'A' && c(j) == 'C' && c(t) == 'G'){
        return false;
    }else if(c(l) == 'A' && c(j) == 'G' && c(t) == 'C'){
        return false;
    }else if(c(l) == 'A' && c(k) == 'G' && c(t) == 'C'){
        return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    Combination comb(110);
    ll dp[110][4][4][4] = {}; //i番目までみて,そこまでの文字列がj,k,l
    dp[0][0][0][0] = 1;
    rep(i,0,N){
        rep(j,0,4){
            rep(k,0,4){
                rep(l,0,4){
                    rep(t,0,4){
                        if(check(t,j,k,l)){
                            dp[i+1][t][j][k] += dp[i][j][k][l] % MOD;
                            dp[i+1][t][j][k] %= MOD;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i,0,4){
        rep(j,0,4){
            rep(k,0,4){
                ans += dp[N][i][j][k] % MOD;
                ans %= MOD;
            }
        }
    }
    print(ans);

    // ll dp[110][4] = {};
    // dp[0][0] = 1;
    // rep(i,0,N){
    //     rep(j,0,4){
    //         if(j == 0){
    //             rep(k,0,4){
    //                 dp[i+1][j] += dp[i][k];
    //             }
    //         }
    //     }
    // }




}