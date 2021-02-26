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
ll N;
ll a[410];
ll dp[410][410] = {};
ll sum[410] = {};
ll dfs(ll lv, ll rv){
    ll &res = dp[lv][rv];
    if(~res) return res;
    res = INF;
    if(lv+1 == rv){
        res = 0;
        return 0;
    }
    rep(k,lv+1,rv){
        res = min(res, dfs(lv,k) + dfs(k,rv) + (sum[rv] - sum[lv]));
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    rep(i,0,N){
        sum[i+1] = sum[i] + a[i];
    }
    dfs(0,N);
    print(dp[0][N]);


}
