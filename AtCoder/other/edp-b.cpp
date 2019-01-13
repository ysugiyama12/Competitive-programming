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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    ll h[100010];
    cin >> N >> K;
    rep(i,0,N){
        cin >> h[i];
    }
    ll dp[100010] = {};
    dp[0] = 0;
    rep(i,1,N){
        dp[i] = INF;
    }
    rep(i,1,N){
        ll v = max(0LL, i - K);
        // print(v);
        rep(j, v, i){
            // print2(v,i-1);
            dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
        }
        // print(dp[i]);
        // ll v = min(0LL, i - K);
        // // dp[i+1] = -1;
        // rrep(v,i-1,0){
        //     if(v == i-1){
        //         dp[i+1] = dp[i-v] + abs(h[i-v] + h[i+1]);
        //     }
        //     dp[i+1] = min(dp[i+1], dp[i-v] + abs(h[i-v] + h[i+1]));
        // }
    }
    print(dp[N-1]);

}
