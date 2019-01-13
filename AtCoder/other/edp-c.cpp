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
    ll N;
    ll a[100010], b[100010], c[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i] >> b[i] >> c[i];
    }
    ll dp[100010][3] = {};
    rep(i,0,N){
        dp[i+1][0] = max(dp[i][1] + b[i], dp[i][2] + c[i]);
        dp[i+1][1] = max(dp[i][0] + a[i], dp[i][2] + c[i]);
        dp[i+1][2] = max(dp[i][0] + a[i], dp[i][1] + b[i]);
    }
    ll ans = max(dp[N][0], max(dp[N][1], dp[N][2]));
    print(ans);
}
