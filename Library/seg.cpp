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
struct LCA {
private:
    ll N;
    vector<int> tree[200010];
    ll logN;
    int parent[200010] = {};
    int depth[200010] = {};
    int next_val[25][200010] = {};
    ll p;
public:

    void build(ll n, vector<int> t[], ll pa = 0){
        N = n;
        p = pa;
        rep(i,0,N) tree[i] = t[i];
        logN = floor(log2(N)) + 1;
        dfs(p, -1, 0);
        rep(i,0,N){
            next_val[0][i] = parent[i];
        }
        rep(k,0,logN){
            rep(i,0,N){
                if(next_val[k][i] == -1){
                    next_val[k+1][i] = -1;
                }else{
                    next_val[k+1][i] = next_val[k][next_val[k][i]];
                }
            }
        }
    }

    void dfs(ll cur, ll par, ll d){
        depth[cur] = d;
        parent[cur] = par;
        for(auto &e: tree[cur]){
            if(e == par) continue;
            dfs(e, cur, d+1);
        }
    }

    ll getParent(ll cur, ll num) {
        ll p = cur;
        rrep(k,logN-1, 0){
            if(p == -1){
                break;
            }
            if((num >> k) & 1){
                p = next_val[k][p];
            }
        }
        return p;
    }

    ll getLCA(ll va, ll vb){
        if(depth[va] > depth[vb]){
            va = getParent(va, depth[va] - depth[vb]);
        }else if(depth[va] < depth[vb]){
            vb = getParent(vb, depth[vb] - depth[va]);
        }
        ll lv = -1, rv = N+1;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            ll ta = getParent(va, mid);
            ll tb = getParent(vb, mid);
            if(ta == -1 || tb == -1){
                rv = mid;
            }else if(ta != tb){
                lv = mid;
            }else{
                rv = mid;
            }
        }
        return getParent(va, rv);
    }
} lca;

struct LazySegmentTree {
private:
    ll n;
    vector<ll> node, lazy, lazy_num;

public:
    LazySegmentTree(vector<ll> v) {
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        lazy_num.resize(2*n-1, 0);
        rep(i,0,sz){
            lazy_num[i+n-1] = v[i];
        }
        rrep(i,n-2,0) lazy_num[i] = lazy_num[2*i+1] + lazy_num[2*i+2];

        // for(ll i=0; i<sz; i++) node[i+n-1] = 0;
        // for(ll i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(ll k, ll l, ll r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k] * lazy_num[k];
            if(r - l > 1) {
                // lazy[2*k+1] += lazy[k] / 2;
                // lazy[2*k+2] += lazy[k] / 2;
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];               
            }
            lazy[k] = 0;
        }
    }

    void add(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            // lazy[k] += (r - l) * x;
            lazy[k] += x;
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
vector<int> tree[150010];
vector<ll> euler;
vector<ll> euler_edge;
ll v_begin[150010] = {}, v_end[150010] = {};

ll idx = 0;
void dfs(ll cur, ll par){
    v_begin[cur] = idx;
    idx++;
    euler.push_back(cur);

    for(auto &e: tree[cur]){
        if(e == par) continue;
        euler_edge.push_back(1);
        dfs(e, cur);
        euler_edge.push_back(-1);
        euler.push_back(cur);
        idx++;
    }
    v_end[cur] = idx;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q;
    cin >> N >> Q;
    ll a[150010], b[150010];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    dfs(0, -1);

    LazySegmentTree sg(euler_edge);
    lca.build(N, tree);
    
    while(Q--){
        ll t;
        cin >> t;
        if(t == 0){
            ll u,v;
            cin >> u >> v;
            ll lc = lca.getLCA(u, v);
            ll ans = sg.getsum(0, v_begin[u]) + sg.getsum(0, v_begin[v]) - 2 * sg.getsum(0, v_begin[lc]);
            print(ans);
        }else{
            ll v,x;
            cin >> v >> x;
            sg.add(v_begin[v], v_end[v]-1, x);

        }
    }

    

}