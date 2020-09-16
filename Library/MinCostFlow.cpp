/*** author: yuji9511 ***/
// verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

struct MinCostFlow {
private:
    typedef struct {
        ll to, cap, cost, rev;
    } edge;
    ll N;
    vector<edge> tree[1010];
    ll dist[1010] = {};
    ll h[1010];
    ll prevv[1010];
    ll preve[1010];

public:
    MinCostFlow(ll n){
        N = n;
    }

    void add_edge(ll from, ll to, ll cap, ll cost){
        tree[from].push_back({to, cap, cost, (ll)tree[to].size()});
        tree[to].push_back({from, 0LL, -cost, (ll)(tree[from].size()-1)});
    }

    ll min_cost_flow(ll s, ll t, ll f){
        ll res = 0;
        fill(h, h+N, 0);
        while(f > 0){
            priority_queue<lpair, vector<lpair>, greater<lpair> > que;
            fill(dist, dist+N, INF);
            dist[s] = 0;
            que.push({0,s});
            while(not que.empty()){
                lpair p = que.top();
                que.pop();
                ll v = p.second;
                if(dist[v] < p.first) continue;
                ll i = 0;
                for(auto &e: tree[v]){
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push({dist[e.to], e.to});
                    }
                    i++;
                }
            }
            if(dist[t] == INF){
                return -1;
            }
            rep(v,0,N) h[v] += dist[v];
            ll d = f;
            for(ll v = t; v != s; v = prevv[v]){
                d = min(d, tree[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for(ll v = t; v != s; v = prevv[v]){
                edge &e = tree[prevv[v]][preve[v]];
                e.cap -= d;
                tree[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

void solve(){
    ll V,E,F;
    cin >> V >> E >> F;
    MinCostFlow mf(V);
    rep(i,0,E){
        ll u,v,c,d;
        cin >> u >> v >> c >> d;
        mf.add_edge(u, v, c, d);
    }
    ll ans = mf.min_cost_flow(0, V-1, F);
    print(ans);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}