/*** author: yuji9511 ***/
// verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
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

struct MaximumFlow {
private:
    typedef struct {
        ll to, cap, rev;
    } edge;
    ll N;
    bool used[1010] = {};
    vector<edge> tree[1010];

public:
    MaximumFlow(ll n){
        N = n;
    }

    void add_edge(ll from, ll to, ll cost){
        tree[from].push_back({to, cost, (ll) tree[to].size()});
        tree[to].push_back({from, 0LL, (ll)(tree[from].size() - 1)});
    }

    ll dfs(ll v, ll t, ll f){
        if(v == t) return f;
        used[v] = true;
        for(auto &e: tree[v]){
            if(!used[e.to] && e.cap > 0){
                ll d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    tree[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll maxflow(ll st, ll dt){
        ll flow = 0;
        while(true){
            memset(used, 0, sizeof(used));
            ll f = dfs(st, dt, INF);
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
};

void solve(){
    ll V,E;
    cin >> V >> E;
    MaximumFlow mf(V);
    rep(i,0,E){
        ll u,v,c;
        cin >> u >> v >> c;
        mf.add_edge(u,v,c);
    }
    ll ans = mf.maxflow(0,V-1);
    print(ans);
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}