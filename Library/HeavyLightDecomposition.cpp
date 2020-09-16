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

// verify: https://yukicoder.me/submissions/476102
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




struct AddLazySegmentTree {
private:
    ll n;
    vector<ll> node, lazy;

public:
    AddLazySegmentTree(vector<ll> v) {
        ll sz = (ll)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(ll i=0; i<sz; i++) node[i+n-1] = v[i];
        for(ll i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(ll k, ll l, ll r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    HeavyLightDecomposition hld(N);
    rep(i,0,N-1){
        ll u,v;
        cin >> u >> v;
        u--; v--;
        hld.add_edge(u,v);
    }
    hld.build();
    ll Q;
    cin >> Q;
    vector<ll> v(N,0);
    AddLazySegmentTree sg(v);

    while(Q--){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        auto q = hld.query(a,b);
        for(auto &e: q){
            sg.add(e.first, e.second, 1);
        }
    }

    ll ans = 0;
    rep(i,0,N){
        ll r = sg.getsum(i,i+1);
        ans += r * (r+1) / 2;
    }
    print(ans);
    

}