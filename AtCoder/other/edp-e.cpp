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
    rep(i,0,N+1){
        rep(j,0,100010){
            dp[i][j] = INF;
        }

    }
    dp[0][0] = 0;
    rep(i,0,N){
        rep(j,0,100010){
            if(j - v[i] >= 0){
                dp[i+1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    ll ans = 0;
    rep(i,0,100010){
        if(dp[N][i] <= W){
            ans = i;
        }
    }
    print(ans);
}
