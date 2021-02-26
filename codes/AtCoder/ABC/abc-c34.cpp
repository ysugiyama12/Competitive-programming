#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
const ll max_N = 210000;
ll fac[max_N + 1000], facinv[max_N + 1000];

ll power(ll x, ll n){ // xのn乗 % MOD
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1){
        res = res * x % MOD;
    }
    return res;
}

ll nck(ll n, ll k){
    if(k == 0 || n == k){
        return 1;
    }
    return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
}
void comb_setup(){
    fac[0] = 0;
    fac[1] = 1;
    rep(i,2,max_N){
        fac[i] = (fac[i-1] * i) % MOD;
    }
    rep(i,0,max_N){
        facinv[i] = power(fac[i], MOD - 2);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll W,H;
    cin >> W >> H;
    comb_setup();
    ll ans = nck(W+H-2,W-1) % MOD;
    print(ans);

}
