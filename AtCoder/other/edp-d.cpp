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
ll dp[110][100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,W;
    ll w[110], v[110];
    cin >> N >> W;
    rep(i,0,N){
        cin >> w[i] >> v[i];
    }
    rep(i,0,N){
        rep(j,0,W+1){
            if(j - w[i] >= 0){
                dp[i+1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    print(dp[N][W]);
}
