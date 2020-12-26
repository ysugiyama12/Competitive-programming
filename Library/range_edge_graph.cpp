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

template<typename W>
struct range_edge_graph {
    int n;
    struct edge { int to; W weight;};
    vector<vector<edge>> g;
    
    range_edge_graph(int n) : n(n) {
        g.resize(3*n);
        for (int i = 1; i < n; ++i) {
            int cl = i<<1|0, cr = i<<1|1;
            add_edge(i, cl, 0);
            add_edge(i, cr, 0);
            add_edge(cl+2*n, i+2*n, 0);
            add_edge(cr+2*n, i+2*n, 0);
        }
    }

    // map [3n, 4n) -> [n, 2n)
    void add_edge(int u, int v, W w) {
        if (3*n <= u) u -= 2*n;
        g[u].push_back({v, w});
    }

    // from [l1, r1) to [l2, r2)
    void add_edge(int l1, int r1, int l2, int r2, W w) {
        int idx = g.size();
        for (l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {
            if (l1 & 1) add_edge(l1+2*n, idx, 0), l1++;
            if (r1 & 1) --r1, add_edge(r1+2*n, idx, 0);
        }
        vector<edge> node;
        for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {
            if (l2 & 1) node.push_back({l2++, w});
            if (r2 & 1) node.push_back({--r2, w});
        }
        g.push_back(node);
    }

    vector<W> dijkstra(int s) {
        s += n;
        vector<W> dist(g.size(), INF);
        dist[s] = 0;
        using P = pair<W, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, s);
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (edge& e : g[v]) {
                if (dist[e.to] > dist[v] + e.weight) {
                    dist[e.to] = dist[v] + e.weight;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
        vector<W> res(dist.begin() + n, dist.begin() + 2*n);
        return res;
    }
};

void solve(){
    ll N,M;
    cin >> N >> M;
    range_edge_graph<ll> graph(N+1);
    rep(i,0,M){
        ll l,r,c;
        cin >> l >> r >> c;
        l--; r--;
        graph.add_edge(l, r+1, l, r+1, c);
    }
    auto res = graph.dijkstra(0);
    if(res[N-1] == INF){
        print(-1);
    }else{
        print(res[N-1]);
    }
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}