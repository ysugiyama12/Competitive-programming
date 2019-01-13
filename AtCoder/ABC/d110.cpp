#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;
const ll max_N = 110000;
ll fac[max_N + 1000], facinv[max_N + 1000];
const ll MOD = 1e9 + 7;
ll N,M;

ll power(ll x, ll n){
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

ll npk(ll n, ll k){
    if(k == 0 || n == k){
        return 1;
    }
    return fac[n] * facinv[n-k] % MOD;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll a = 2;
    ll val[max_N] = {};
    ll m = M;
    while(a * a <= M){
        while(m % a == 0){
            m /= a;
            val[a]++;
        }
        a++;
    }
    fac[0] = 0;
    fac[1] = 1;
    rep(i,2,max_N){
        fac[i] = (fac[i-1] * i) % MOD;
    }
    rep(i,0,N+1){
        facinv[i] = power(fac[i], MOD - 2);
    }
    ll ans = 1;
    if(m != 1){
        ans *= N;
        ans %= MOD;
    }

    rep(i,0,max_N){
        if(val[i] != 0){
            ans *= nck(val[i] + N - 1, N - 1);
            ans %= MOD;
        }
    }
    print(ans);

}
