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
ll x[100010], y[100010];
vector<ll> tree[100010];
ll dp[100010][2] = {};
ll dfs(ll cur, ll par, ll color){
    ll &res = dp[cur][color];
    if(~res) return res;
    if(tree[cur].size() == 1 && cur != 0){
        res = 1;
        return 1;
    }
    res = 1;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        ll tmp = 0;
        tmp += dfs(e, cur, 1) % MOD;
        if(color == 1){
            tmp += dfs(e, cur, 0) % MOD;
            tmp %= MOD;
        }
        res *= tmp;
        res %= MOD;
    }
    // if(cur == 0) print(res);
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        tree[x[i]].push_back(y[i]);
        tree[y[i]].push_back(x[i]);
    }
    if(N == 1){
        print(2);
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    ll ans = (dfs(0, -1, 0) + dfs(0,-1, 1)) % MOD;
    print(ans);
}
