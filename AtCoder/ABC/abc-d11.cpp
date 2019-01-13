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
double fac(ll x){
    if(x == 0) return 1;
    double v = 1;
    rep(i,1,x+1){
        v *= i;
    }
    return v;
}
double nck(ll n, ll k){
    return fac(n)/(fac(n-k) * fac(k));
}
// nCk % MODのテーブル作成関数
// const ll max_N = 110000;
// ll fac[max_N + 1000], facinv[max_N + 1000];

// ll power(ll x, ll n){ // xのn乗 % MOD
//     if(n == 0) return 1LL;
//     ll res = power(x * x % MOD, n/2);
//     if(n % 2 == 1){
//         res = res * x % MOD;
//     }
//     return res;
// }

// ll nck(ll n, ll k){
//     if(k == 0 || n == k){
//         return 1;
//     }
//     return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
// }

// ll npk(ll n, ll k){
//     if(k == 0 || n == k){
//         return 1;
//     }
//     return fac[n] * facinv[n-k] % MOD;
// }

// void comb_setup(){
//     fac[0] = 0;
//     fac[1] = 1;
//     rep(i,2,max_N){
//         fac[i] = (fac[i-1] * i) % MOD;
//     }
//     rep(i,0,max_N){
//         facinv[i] = power(fac[i], MOD - 2);
//     }
// }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,D,X,Y;
    cin >> N >> D >> X >> Y;
    if(N > 30) return 0;
    double cnt = 0;
    // comb_setup();
    // print(pow(4,N));
    // rep(t,0,pow(4,N)){
    //     ll val[20] = {};
    //     ll tt = t;
    //     ll idx = 0;
    //     while(tt > 0){
    //         val[idx] = tt % 4;
    //         tt /= 4;
    //         idx++;
    //     }
    //     ll x = 0, y = 0;
    //     rep(i,0,N){
    //         if(val[i] == 0){
    //             x += D;
    //         }else if(val[i] == 1){
    //             x -= D;
    //         }else if(val[i] == 2){
    //             y += D;
    //         }else{
    //             y -= D;
    //         }
    //     }
    //     // printa(val,N);
    //     if(x == X && y == Y){
    //         cnt++;
    //     }
    // }
    // print(cnt);
    // double ans = cnt/pow(4,N);
    // cout << setprecision(12) << ans << endl;
    if(abs(X) % D != 0 || abs(Y) % D != 0){
        print(0.0);
        return 0;
    }
    ll x = abs(X)/D;
    ll y = abs(Y)/D;
    if(x + y > N){
        print(0.0);
        return 0;
    }
    if((N - x - y) % 2 == 1){
        print(0.0);
        return 0;
    }
    double ans = 0;
    rep(i,0,N+1){ //左右がN回のうちi回
        // cout << "i = " << i << endl;
        ll j = N-i;
        if((i - x) < 0 || (i - x) % 2 == 1) continue;
        if((j - y) < 0 || (j - y) % 2 == 1) continue;
        ll ix = (x+i)/2;
        ll iy = (y+j)/2;
        // print(ix);
        // print(iy);
        double tt = nck(N,i) * nck(i,ix) * nck(j,iy);
        tt /= pow(4,N);
        ans += tt;
    }
    cout << setprecision(12) << ans << endl;
    // ll val = (N - x - y)/2;
    // ll bunsi = 0;
    // double kk = 0;
    // rep(i,0,val+1){
    //     ll tt = val - i;
    //     // print(tt);
    //     // print(tt);
    //     double bunbo = fac(x+tt) * fac(tt) * fac(y+i) * fac(i);
    //     // print(bunbo);
    //     double k = (double)fac(N) / (double) bunbo;
    //     // print(k);
    //     kk += k;
    // }
    // double ans = kk / pow(4,N);
    // cout << setprecision(12) << ans << endl;

}
