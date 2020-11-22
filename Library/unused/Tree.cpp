/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

struct Tree {
private:
    ll N, logN;
    vector<lpair> edge[200010];
    ll depth[200010] = {};
    ll sum[200010] = {};
    ll parent[200010] = {};
    ll next_val[20][200010] = {};
public:
    Tree(){
    }

    void init(ll n){
        N = n;
        logN = floor(log2(N)) + 1;
    }

    ll getDepth(ll x) { return depth[x]; }
    ll getSum(ll x) { return sum[x]; }

    void add(ll x, ll y, ll z){ edge[x].push_back({y,z}); }

    void prepare(){
        dfs_parent();
        dfs_sum();
        makeDoubling();
    }

    void dfs_parent(ll cur = 0, ll par = -1, ll d = 0){
        depth[cur] = d;
        parent[cur] = par;
        for(auto &e: edge[cur]){
            if(e.first == par) continue;
            dfs_parent(e.first, cur, d+1);
        }
    }

    void dfs_sum(ll cur = 0, ll par = -1, ll d = 0){
        if(par != -1) sum[cur] = sum[par] + d;
        for(auto &e: edge[cur]){
            if(e.first == par) continue;
            dfs_sum(e.first, cur, e.second);
        }
    }

    void makeDoubling(){
        rep(i,0,N) next_val[0][i] = parent[i];
        rep(k,0,logN){
            rep(i,0,N){
                if(next_val[k][i] == -1) next_val[k+1][i] = -1;
                else next_val[k+1][i] = next_val[k][next_val[k][i]];
            }
        }
    }

    ll getParent(ll cur, ll num) {
        ll p = cur;
        rrep(k,logN-1, 0){
            if(p == -1) break;
            if((num >> k) & 1) p = next_val[k][p];
        }
        return p;
    }

    ll getLCA(ll va, ll vb){
        if(depth[va] > depth[vb]) va = getParent(va, depth[va] - depth[vb]);
        else if(depth[va] < depth[vb]) vb = getParent(vb, depth[vb] - depth[va]);
        ll lv = -1, rv = N+1;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            ll ta = getParent(va, mid), tb = getParent(vb, mid);
            if(ta == -1 || tb == -1) rv = mid;
            else if(ta != tb) lv = mid;
            else rv = mid;
        }
        return getParent(va, rv);
    }
} tree;


// verify: https://atcoder.jp/contests/abc014/tasks/abc014_4
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    tree.init(N);
    rep(i,0,N-1){
        ll u,v;
        cin >> u >> v;
        u--; v--;
        tree.add(u,v,1);
        tree.add(v,u,1);
    }
    tree.prepare();
    
    ll Q;
    cin >> Q;
    while(Q--){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        ll p = tree.getLCA(a,b);
        ll ans = tree.getDepth(a) + tree.getDepth(b) - 2 * tree.getDepth(p) + 1;
        print(ans);
    }
}