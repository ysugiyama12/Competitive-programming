#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

ll power(ll x, ll n){ // xのn乗 % MOD
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1){
        res = res * x % MOD;
    }
    return res;
}

inline vector<ll> factor(ll M){ //素因数分解
    vector<ll> dd;
    if(M == 1){
        dd.push_back(1);
        return dd;
    }
    for(ll i = 2; i*i <= M; i++){
        while(M % i == 0){
            dd.push_back(i);
            M /= i;
        }
    }
    if(M != 1) dd.push_back(M);
    sort(dd.begin(), dd.end());
    return dd;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    vector<ll> dd = factor(N);
    map<ll, ll> mp;
    rep(i,0,dd.size()){
        mp[dd[i]]++;
    }
    ll fac_inv[55] = {};
    rep(i,0,52){
        fac_inv[i] = power(i, MOD-2) % MOD;
    }
    ll ans = 1;
    for(auto &e: mp){
        ll dp[10010][50] = {};
        ll p = e.first;
        ll A = e.second;
        dp[0][A] = 1;
        rep(k,0,K){
            rep(a,0,A+1){
                rep(b,a,A+1){
                    dp[k+1][a] += fac_inv[b+1] * dp[k][b] % MOD;
                    dp[k+1][a] %= MOD;
                }
            }
        }
        ll tt = 0;
        rep(a,0,A+1){
            tt += power(p,a) * dp[K][a] % MOD;
            tt %= MOD;
        }
        ans *= tt;
        ans %= MOD;
    }
    ans = (ans + MOD) % MOD;
    print(ans);

}
