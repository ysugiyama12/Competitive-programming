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
// verify: https://atcoder.jp/contests/past201912-open/submissions/12485980

struct LCA {
private:
    ll N;
    vector<int> tree[200010];
    ll logN;
    vector<int> parent;
    vector<int> depth;
    int next_val[20][200010] = {};
    ll p;
public:

    LCA(ll n){
        N = n;
        logN = floor(log2(N)) + 1;
        parent.assign(N, 0);
        depth.assign(N, 0);
    }

    void add_edge(ll from, ll to){
        tree[from].push_back(to);
    }

    void build(ll pa = 0){
        p = pa;
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
};
LCA lca(200000);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll par = -1;
    rep(i,0,N){
        ll p;
        cin >> p;
        if(p == -1){
            par = i;
        }else{
            p--;
            lca.add_edge(i, p);
            lca.add_edge(p, i);
        }
    }
    lca.build(par);
    ll Q;
    cin >> Q;

    while(Q--){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        if(lca.getLCA(a,b) == b){
            print("Yes");
        }else{
            print("No");
        }
    }

}
