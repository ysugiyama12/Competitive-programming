#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
// nCk % MODのテーブル作成関数
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

ll divide[1010][1010] = {};
ll calc(ll N, ll M){
    ll &res = divide[N][M];
    if(~res) return res;
    if(N == 0) return res = 1;
    if(M == 1) return res = 1;
    res = 0;
    if(N < M) return res = calc(N,N) % MOD;
    return res = (calc(N, M-1) % MOD + calc(N-M,M) % MOD) % MOD;
}
ll dp[1010][1010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll killA[110], killB[110];
    rep(i,0,N) cin >> killA[i];
    rep(i,0,M) cin >> killB[i];
    ll sum_a = 0, sum_b = 0;
    rep(i,0,N) sum_a += killA[i];
    rep(i,0,M) sum_b += killB[i];
    comb_setup();
    memset(divide, -1, sizeof(divide));
    ll tmp = calc(N,M);
    vector<ll> dn, dm;
    ll cnt = 1;
    rep(i,1,N){
        if(killA[i] != killA[i-1]){
            dn.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    dn.push_back(cnt);
    cnt = 1;
    rep(i,1,M){
        if(killB[i] != killB[i-1]){
            dm.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    dm.push_back(cnt);

    ll n = dn.size();
    dp[0][0] = 1;
    rep(i,0,n){
        rep(j,0,sum_b+1){
            rep(k,0,sum_b+1){
                if(j - k >= 0){
                    dp[i+1][j] += dp[i][j-k] * calc(k, dn[i]) % MOD;
                    dp[i+1][j] %= MOD;
                }
            }
        }
    }
    ll ans1 = dp[n][sum_b];
    n = dm.size();
    rep(i,0,1001){
        rep(j,0,1001){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    rep(i,0,n){
        rep(j,0,sum_a+1){
            rep(k,0,sum_a+1){
                if(j - k >= 0){
                    dp[i+1][j] += dp[i][j-k] * calc(k, dm[i]) % MOD;
                    dp[i+1][j] %= MOD;
                }
            }
        }
    }
    ll ans2 = dp[n][sum_a];
    ll ans = ans1 * ans2 % MOD;
    print(ans);






}
