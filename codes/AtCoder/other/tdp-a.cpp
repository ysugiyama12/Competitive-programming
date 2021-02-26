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
ll dp[110][10010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll p[110];
    cin >> N;
    rep(i,0,N){
        cin >> p[i];
    }
    dp[0][0] = 1;
    rep(i,0,N){
        rep(n,0,10001){
            dp[i+1][n] = dp[i][n];
            if(n - p[i] >= 0){
                dp[i+1][n] += dp[i][n-p[i]];
                // print(dp[i+1][n]);
            }
        }
        // rep(j,0,10){
        //     cout << dp[i+1][j] << " ";
        // }
        // cout << endl;
    }
    ll ans = 0;
    rep(i,0,10001){
        if(dp[N][i] != 0) ans++;
    }
    print(ans);
}

