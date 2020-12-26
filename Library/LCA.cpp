/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
// https://atcoder.jp/contests/past201912-open/submissions/18997721
template< typename G >
struct LCA {
    const int LOG;
    vector<int> dep;
    const G &g;
    vector< vector<int> > table;

    LCA(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to : g[idx]) {
            if(to != par) dfs(to, idx, d + 1);
        }
    }

    void build(int par = 0) {
        dfs(par, -1, 0);
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < table[k].size(); i++) {
                if(table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int u, int v) {
        if(dep[u] > dep[v]) swap(u, v);
        for(int i = LOG - 1; i >= 0; i--) {
            if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if(u == v) return u;
        for(int i = LOG - 1; i >= 0; i--) {
            if(table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};

void solve(){
    ll N;
    cin >> N;
    ll par = -1;
    vector<vector<int> > tree(N);
    rep(i,0,N){
        ll p;
        cin >> p;
        if(p == -1){
            par = i;
        }else{
            p--;
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
    }
    LCA lca(tree);
    lca.build(par);
    ll Q;
    cin >> Q;

    while(Q--){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        if(lca.query(a,b) == b){
            print("Yes");
        }else{
            print("No");
        }
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}