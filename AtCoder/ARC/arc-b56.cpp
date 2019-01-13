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
ll u[200010], v[200010];
vector<ll> tree[200010];
ll N,M,S;
bool check[200010];
void dfs(ll cur){
    if(check[cur]) return;
    check[cur] = true;
    for(auto &e : tree[cur]){
        if(!check[e]){
            dfs(e);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> S;
    S--;
    rep(i,0,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
    }
    if(N > 2000) return 0;
    rep(i,0,N){
        rep(j,0,N){
            check[j] = false;
        }
        rep(j,0,i){
            check[j] = true;
        }
        dfs(S);
        if(check[i]){
            print(i+1);
        }
    }



}
