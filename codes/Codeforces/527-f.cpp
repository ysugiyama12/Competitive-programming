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
ll a[200010];
ll x[200010], y[200010];
ll res;
ll ans = 0;
vector<ll> tree[200010];
ll sum[200010] = {};
void dfs(ll cur, ll par,ll depth){
    res += a[cur] * depth;
    sum[cur] += a[cur];
    for(auto &e : tree[cur]){
        if(e != par){
            dfs(e, cur, depth+1);
            sum[cur] += sum[e];
        }
    }
}

void dfs2(ll cur, ll par){
    // print2(cur,res);
    ans = max(ans, res);
    for(auto &e : tree[cur]){
        if(e != par){
            res -= sum[e];
            sum[cur] -= sum[e];
            res += sum[cur];
            sum[e] += sum[cur];
            dfs2(e, cur);
            sum[e] -= sum[cur];
            res -= sum[cur];
            sum[cur] += sum[e];
            res += sum[e];
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    rep(i,0,N-1){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    rep(i,0,N-1){
        tree[x[i]].push_back(y[i]);
        tree[y[i]].push_back(x[i]);
    }
    dfs(0, -1, 0);

    dfs2(0,-1);
    print(ans);
}
