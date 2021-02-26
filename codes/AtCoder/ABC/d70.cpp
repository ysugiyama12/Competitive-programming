#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

typedef struct{
    ll to;
    ll cost;
} edge;

using namespace std;
int N;
ll a[100010], b[100010], c[100010];
ll Q,K;
ll x[100010], y[100010];
ll dist[100010];
vector<edge> tree[100010];

void dfs(ll v, ll p, ll d){
    // v: 現在位置 p: 親ノード d: 基準点からの距離
    dist[v] = d;
    for(auto &e : tree[v]){
        if(e.to == p){
            continue;
        }
        dfs(e.to, v, d + e.cost);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    cin >> Q >> K;
    K--;
    rep(i,0,Q){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    rep(i,0,N-1){
        edge ed = {b[i], c[i]};
        tree[a[i]].push_back(ed);
        ed.to = a[i];
        tree[b[i]].push_back(ed);
    }
    dfs(K, -1, 0);
    rep(i,0,Q){
        print(dist[x[i]] + dist[y[i]]);
    }


}
