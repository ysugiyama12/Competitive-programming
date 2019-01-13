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
ll dp[3010][3010][2]= {};
ll N;
ll a[3010];

ll dfs(ll lv=0, ll rv=N-1, ll turn=0){
    ll &res = dp[lv][rv][turn];
    if(~res) return res;
    res = 0;
    if(lv == rv){
        res = a[lv];
        return res;
    }
    res = -INF;
    if(turn == 0){
        res = max(a[lv] - dfs(lv+1, rv, 1), a[rv] - dfs(lv, rv-1, 1));
    }else{
        res = max(a[lv] - dfs(lv+1, rv, 0), a[rv] - dfs(lv, rv-1, 0));
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
    memset(dp,-1, sizeof(dp));
    ll ans = dfs();
    print(ans);

}
