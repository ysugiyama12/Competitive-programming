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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,A;
    ll x[55];
    cin >> N >> A;
    rep(i,0,N){
        cin >> x[i];
        x[i] -= A;
    }
    ll dp[55][5010] = {}; // i枚目までみたときの平均がn
    ll pad = 2500;
    dp[0][pad] = 1;
    rep(i,0,N){
        rep(n,0,5001){
            dp[i+1][n] += dp[i][n];
            if(n - x[i] >= 0){
                dp[i+1][n] += dp[i][n-x[i]]; 
            }
        }
    }
    print(dp[N][pad]-1);


}
