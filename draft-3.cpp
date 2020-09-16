/*** author: yuji9511 ***/
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
ll check[310] = {};
ll c0 = 0, c1 = 0;
vector<ll> tree[310];
ll color[310] = {};
vector<ll> v0, v1;

void dfs(ll cur, ll par, ll d){
    if(check[cur]) return;
    check[cur] = true;
    color[cur] = d;
    if(d == 0) v0.push_back(cur);
    else v1.push_back(cur);
    for(auto &e: tree[cur]){
        if(e == par) continue;
        if(check[e] == true) continue;
        dfs(e, cur, d^1);
    }
}

typedef struct {
    ll to;
    ll cap;
    ll rev;
} edge;

struct MaxFlow {
private:
    ll N;
    bool used[1010] = {};
    vector<edge> tree[1010];

public:
    MaxFlow(ll n){
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

// bool used[310] = {};
// vector<edge> tree2[310];

// ll dfs2(ll v, ll t, ll f){
//     if(v == t) return f;
//     used[v] = true;
//     for(auto &e: tree2[v]){
//         if(!used[e.to] && e.cap > 0){
//             ll d = dfs2(e.to, t, min(f, e.cap));
//             if(d > 0){
//                 e.cap -= d;
//                 // print(tree2[e.to].size(), e.rev);
//                 tree2[e.to][e.rev].cap += d;
//                 return d;
//             }
//         }

//     }
//     return 0;
// }

void solve(){
    ll N,M,K;
    cin >> N >> M >> K;
    char c[310];
    rep(i,0,N) cin >> c[i];
    ll dist[310][310] = {};
    rep(i,0,N){
        rep(j,0,N){
            dist[i][j] = INF;
        }
    }
    rep(i,0,M){
        ll u,v;
        cin >> u >> v;
        u--; v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    map<lpair,bool> is_edge;
    rep(i,0,N){
        rep(j,i+1,N){
            if(dist[i][j] <= K){
                if(c[i] +1 == c[j] || c[j]+1 == c[i] || (c[i] == 'a' && c[j] == 'z') || (c[i] == 'z' && c[j]  == 'a')){
                    tree[i].push_back(j);
                    tree[j].push_back(i);
                    is_edge[{i,j}] = true;
                    is_edge[{j,i}] = true;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,0,N){
        if(check[i]) continue;
        MaxFlow mf(N+10);
        // rep(j,0,N+2){
        //     tree2[j].clear();
        // }
        c0 = 0;
        c1 = 0;
        v0.clear();
        v1.clear();
        dfs(i, -1, 0);
        for(auto &e: v0){
            for(auto &f: v1){
                if(is_edge[{e,f}]){
                    mf.add_edge(e, f, 1);
                    // tree2[e+1].push_back({f+1, 1, (ll) tree2[f+1].size()});
                    // tree2[f+1].push_back({e+1, 0LL, (ll)(tree2[e+1].size() - 1)});
                }
            }
        }
        for(auto &e: v0){
            mf.add_edge(N, e, 1);
                // tree2[0].push_back({e+1, 1, (ll) tree2[e+1].size()});
                // tree2[e+1].push_back({0, 0LL, (ll)(tree2[N].size() - 1)});   
        }
        for(auto &e: v1){
            mf.add_edge(e, N+1, 1);
                // tree2[e+1].push_back({N+1, 1, (ll) tree2[N+1].size()});
                // tree2[N+1].push_back({e+1, 0LL, (ll)(tree2[e+1].size() - 1)});   
        }
        ans += mf.maxflow(N, N+1);
        // rep(j,0,N){
        //     tree[j].clear();
        // }
        // for(auto &e: v0){
        //     for(auto &f: tree2[e]){
        //         if(f.cap == 0) ans++;
        //     }
        // }
        // // ans += min(c0, c1);
    }
    print(ans);


    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}