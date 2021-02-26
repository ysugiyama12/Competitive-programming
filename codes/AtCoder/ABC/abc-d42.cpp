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
const ll max_N = 200000;
ll fac[max_N + 1000], facinv[max_N + 1000];
ll N,K;

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
    ll H,W,A,B;
    cin >> H >> W >> A >> B;
    fac[0] = 0;
    fac[1] = 1;
    rep(i,2,max_N){
        fac[i] = (fac[i-1] * i) % MOD;
    }
    rep(i,0,max_N){
        facinv[i] = power(fac[i], MOD - 2);
    }
    ll all_c = nck(H+W-2, H-1);
    ll ab_min = min(A,B);
    ll ex_c = 0;
    rep(i,0,ab_min){
        ex_c += nck(H-A+B-1, B-i-1) * nck(W-B+A-1,A-i-1);
        ex_c %= MOD;
    }
    ll ans = (all_c - ex_c + MOD) % MOD;
    print(ans);

}
