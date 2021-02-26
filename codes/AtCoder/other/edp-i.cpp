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
double dp[3010][6010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    double p[3010];
    cin >> N;
    rep(i,0,N){
        cin >> p[i];
    }
    rep(i,0,N+1){
        rep(j,0,6010){
            dp[i][j] = 0.0;
        }
    }
    dp[0][3000] = 1.0;
    rep(i,0,N){
        rep(j,0,6010){
            dp[i+1][j] += dp[i][j-1] * p[i];
            dp[i+1][j] += dp[i][j+1] * (1 - p[i]);
        }
    }
    // rep(j,0,2*N){
    //     cout << dp[i+1][3000 - j] << " ";
    // }
    // cout << endl;
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(j != 0){
    //             dp[i+1][j] += dp[i][j-1] * p[i];
    //         }
    //         dp[i+1][j] += dp[i][j+1] * (1 - p[i]);
    //         if(j == 0){
    //             dp[i+1][]
    //         }
    //         // if(j <= i+1){
    //         //     dp[i+1][j] += dp[i][j-1] * p[i];
    //         // }
    //         print2(i,j);
    //         print(dp[i+1][j]);
    //     }
    // }
    double ans = 0.0;
    rep(j,0,6010){
        if(j > 3000){
            ans += dp[N][j];
        }
    }
    cout << setprecision(12) << ans << endl;

}
