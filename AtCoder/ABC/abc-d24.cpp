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
ll power(ll x, ll n){ // xのn乗 % MOD
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1){
        res = res * x % MOD;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A,B,C;
    cin >> A >> B >> C;
    ll c = (B * C)%MOD - (A * B) % MOD;
    c %= MOD;
    ll cinv = A*C%MOD - B*C%MOD + A*B%MOD;
    cinv %= MOD;
    c *= power(cinv, MOD-2) % MOD;
    c %= MOD;

    ll r = (B * C)%MOD - (A * C) % MOD;
    r %= MOD;
    ll rinv = A*C%MOD - B*C%MOD + A*B%MOD;
    rinv %= MOD;
    r *= power(rinv, MOD-2) % MOD;
    r %= MOD;
    cout << (r+MOD) % MOD << " " << (c+MOD)%MOD << endl;
}
