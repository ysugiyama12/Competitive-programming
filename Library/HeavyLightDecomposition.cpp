/*** author: yuji9511 ***/
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = int;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
// const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
// https://atcoder.jp/contests/past202010-open/submissions/19013635
class HeavyLightDecomposition {
private:
    void dfs_sz(ll v) {
        for(ll &u : G[v])
            if(u == par[v]) swap(u,G[v].back());
        if(~par[v]) G[v].pop_back();

        for(ll &u : G[v]){
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if(sub[u] > sub[G[v][0]]) swap(u,G[v][0]);
        }
  }

    void dfs_hld(ll v,ll c,ll &pos) {
        vid[v] = pos++;
        inv[vid[v]] = v;
        type[v] = c;
        for(ll u : G[v]){
            if(u == par[v]) continue;
            head[u] = (u == G[v][0] ? head[v] : u);
            dfs_hld(u,c,pos);
        }
    }

public:
    vector< vector<ll> > G;
    vector<ll> vid, head, sub, par, dep, inv, type;
    ll N;

    HeavyLightDecomposition(ll n):
        G(n), vid(n,-1), head(n), sub(n,1),
        par(n,-1), dep(n,0), inv(n), type(n){
            N = n;
        }

    void add_edge(ll u, ll v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(vector<ll> rs = {0}) {
        ll c = 0, pos = 0;
        for(ll r : rs){
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, c++, pos);
        }
    }

    ll lca(ll u,ll v){
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    ll distance(ll u,ll v){
        return dep[u] + dep[v] - 2 * dep[lca(u,v)];
    }

    // for_each(vertex)
    // [l, r) <- attention!!
    template<typename F>
    void for_each(ll u, ll v, const F& f) {
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            f(max(vid[head[v]], vid[u]), vid[v]+1);
            if(head[u] != head[v]) v=par[head[v]];
            else break;
        }
    }

    vector<lpair> query(ll u, ll v){
        vector<lpair> res;
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            res.push_back({max(vid[head[v]], vid[u]), vid[v]+1});
            if(head[u] != head[v]) v = par[head[v]];
            else break;
        }
        return res;
    }

    template<typename T,typename Q,typename F>
    T for_each(ll u, ll v, T ti,const Q &q,const F &f){
        T l = ti,r = ti;
        while(1){
            if(vid[u] > vid[v]){
                swap(u, v);
                swap(l, r);
            }
            l=f(l, q(max(vid[head[v]],vid[u]), vid[v]+1));
            if(head[u] != head[v]) v = par[head[v]];
            else break;
        }
        return f(l, r);
    }

    // for_each(edge)
    // [l, r) <- attention!!
    template<typename F>
    void for_each_edge(ll u, ll v,const F& f) {
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            if(head[u] != head[v]){
                f(vid[head[v]], vid[v]+1);
                v = par[head[v]];
            }else{
                if(u != v) f(vid[u]+1, vid[v]+1);
                break;
            }
        }
    }

    vector<lpair> query_edge(ll u, ll v){
        vector<lpair> res;
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            if(head[u] != head[v]){
                res.push_back({vid[head[v]], vid[v]+1});
                v = par[head[v]];
            }else{
                if(u != v) res.push_back({vid[u]+1, vid[v]+1});
                break;
            }
        }
        return res;
    }
};

typedef struct {
    ll value;
    ll length;
} S;

using F = ll;
ll ID = 1e9+7;

S op(S a, S b){
    return {a.value + b.value, a.length + b.length};
}

S mapping(F f, S a){
    if(f == ID){
        return a;
    }
    return {f, a.length};
}

F composition(F f, F g){ // (f・g)(x) = f(g(x))
    if(f == ID){
        return g;
    }
    return f;
}

S e(){
    return {0,0};
}

F id(){
    return ID;
}

void solve(){
    ll N,Q;
    cin >> N >> Q;
    HeavyLightDecomposition hld(N);
    vll a(N), b(N);
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        hld.add_edge(a[i], b[i]);
    }

    hld.build();
    vector<S> v(N, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> sg(v);

    while(Q--){
        ll u,v,c;
        cin >> u >> v >> c;
        u--; v--;
        hld.for_each_edge(u, v, [&](ll x, ll y){
            sg.apply(x, y, c);
        });
    }
    rep(i,0,N){
        hld.for_each_edge(a[i], b[i], [&](ll x, ll y){
            ll res = sg.get(x).value;
            print(res);
        });
    }

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}