#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)
const ll max_N = 100000;
ll fac[max_N + 10], facinv[max_N + 10];

ll power(ll x, ll n){ // xのn乗 % MOD
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1) res = res * x % MOD;
    return res;
}

ll nck(ll n, ll k){
    if(k == 0 || n == k) return 1;
    return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
}

ll npk(ll n, ll k){
    if(k == 0 || n == k) return 1;
    return fac[n] * facinv[n-k] % MOD;
}

void comb_setup(){
    fac[0] = 1; fac[1] = 1;
    rep(i,2,max_N+1) fac[i] = (fac[i-1] * i) % MOD;
    rep(i,0,max_N+1) facinv[i] = power(fac[i], MOD - 2);
}

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    comb_setup();
    ll sum[100010] = {};
    sum[0] = 1;
    sum[1] = 1;
    rep(i,2,N+1){
        sum[i] = ((sum[i-1] * i + 1) % MOD) * power(i, MOD-2) % MOD;
    }
    rep(i,0,N){
        ans += ((fac[N] * A[i]) % MOD) * (sum[N-i] + sum[i+1] - 1) % MOD;
        ans %= MOD;
    }
    print(ans);



}
