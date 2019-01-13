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
ll dp[210][200010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,W;
    ll v[210], w[210];
    cin >> N >> W;
    ll max_w = 0, max_v = 0;
    rep(i,0,N){
        cin >> v[i] >> w[i];
        max_w = max(max_w, w[i]);
        max_v = max(max_v, v[i]);
    }
    ll val_w = min(max_w * N, W);
    ll val_v = max_v * N;
    if(max_w <= 1000){
        rep(i,0,N){
            rep(j,0,val_w+1){
                if(j >= w[i]){
                    dp[i+1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
                }else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        print(dp[N][val_w]);
    }else if(max_v <= 1000){
        rep(i,0,N){
            rep(j,0,val_v+1){
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        rep(i,0,N){
            rep(j,0,val_v+1){
                if(j >= v[i]){
                    dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
                }else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        ll ans = 0;
        rep(j,0,val_v + 1){
            if(dp[N][j] <= W){
                ans = j;
            }
        }
        print(ans);
    }
}

