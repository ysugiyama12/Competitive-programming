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
ll dp[1010][1010] = {};
char c[1010][1010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W;
    cin >> H >> W;
    rep(i,0,H){
        rep(j,0,W){
            cin >> c[i][j];
        }
    }
    dp[0][0] = 1;
    rep(i,0,H){
        rep(j,0,W){
            if(c[i][j] == '#') continue;
            if(i != 0 && c[i-1][j] == '.'){
                dp[i][j] += dp[i-1][j] % MOD;
            }
            if(j != 0 && c[i][j-1] == '.'){
                dp[i][j] += dp[i][j-1] % MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    print(dp[H-1][W-1]);
}
