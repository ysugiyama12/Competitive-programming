#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18 + 7)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll dp[3010][3010] = {};// dp[i][j]: i回の移動の後、j階にいるような乗り方の総数
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,K;
    ll L[3010], R[3010];
    cin >> N >> M >> K;
    rep(i,0,M) cin >> L[i] >> R[i];
    // ll dp_cur[3010] = {}, dp_next[3010] = {};
    // dp_cur[1] = 1;
    // rep(i,0,K){
    //     memset(dp_next, 0, sizeof(dp_next));
    //     ll sum[3010] = {};
    //     rep(i,0,N+1) sum[i+1] = (sum[i] + dp_cur[i]) % MOD;
    //     rep(i,0,M){
    //         ll v = (sum[R[i]+1] - sum[L[i]] + MOD) % MOD;
    //         dp_next[L[i]] += v % MOD;
    //         dp_next[L[i]] %= MOD;
    //         dp_next[R[i]+1] += (MOD - v) % MOD;
    //         dp_next[R[i]+1] %= MOD;
    //     }
    //     rep(i,0,N+1){
    //         dp_next[i+1] += dp_next[i];
    //         dp_next[i+1] %= MOD;
    //     }
    //     rep(i,0,N+1) dp_cur[i] = dp_next[i];
    // }
    // print(dp_cur[N]);
    dp[0][1] = 1;
    rep(i,0,K){
        ll val[3010] = {};
        rep(j,0,N+1) val[j+1] = (val[j] + dp[i][j]) % MOD;
        rep(j,0,M){
            ll v = (val[R[j]+1] - val[L[j]] + MOD) % MOD;
            dp[i+1][L[j]] += v;
            dp[i+1][L[j]] %= MOD;
            dp[i+1][R[j]+1] += (MOD - v) % MOD;
            dp[i+1][R[j]+1] %= MOD;
        }
        rep(j,0,N+1){
            dp[i+1][j+1] += dp[i+1][j];
            dp[i+1][j+1] %= MOD;
        }
    }
    print(dp[K][N]);
    



 }