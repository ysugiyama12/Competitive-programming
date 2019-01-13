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
ll N,a,b,M;
vector<ll> tree[110];
ll dist[110] = {};
ll dp[110] = {};
ll dfs(ll pos){
    ll val = 0;
    if(dp[pos] != -1){
        return dp[pos];
    }
    for(auto &e : tree[pos]){
        if(dist[pos] == dist[e] + 1){
            val += dfs(e) % MOD;
        }
    }
    dp[pos] = val;
    return val;
    // for(auto &e : tree[pos]){
    //     if(dist[e] == dist[pos] + 1){
    //         cout << pos << " " << e << endl;
    //         dp[e] += dp[pos] % MOD;
    //         dfs(e);
    //     }
    // }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> a >> b;
    a--; b--;
    cin >> M;
    ll x[210], y[210];
    rep(i,0,M){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        tree[x[i]].push_back(y[i]);
        tree[y[i]].push_back(x[i]);
    }
    ll d[110][110] = {};
    rep(i,0,N){
        rep(j,0,N){
            if(i == j){
                d[i][j] = 0;
            }else{
                d[i][j] = INF;
            }
        }
    }
    rep(i,0,M){
        d[x[i]][y[i]] = 1;
        d[y[i]][x[i]] = 1;
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    rep(i,0,N){
        dist[i] = d[a][i];
    }
    rep(i,0,N){
        dp[i] = -1;
    }
    dp[a] = 1;
    ll ans = dfs(b);

    print(ans);




}
