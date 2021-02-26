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
struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;
    vector<ll> diff_weight;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
        rep(i,0,N) diff_weight.push_back(0);
    }

    ll root(ll x){
        if(x == parent[x]){
            return x;
        }else{
            ll r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }

    void unite(ll a, ll b, ll w = 0){
        w += weight(a); w -= weight(b);
        a = root(a); b = root(b);
        if(a == b) return;
        parent[b] = a;
        ll sum = num[a] + num[b];
        num[a] = sum;
        num[b] = sum;
        diff_weight[b] = w;
    }

    bool same(ll a, ll b){ return root(a) == root(b);}
    
    ll sz(ll x){ return num[root(x)];}

    ll weight(ll x){
        root(x);
        return diff_weight[x];
    }

    ll diff(ll a, ll b){
        return weight(b) - weight(a);
    }
};
vector<ll> tree[200010];
ll u[200010], v[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;

    rep(i,0,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
    }
    UnionFind uf(200010);
    rep(i,0,M){
        uf.unite(u[i], v[i]);
    }
    vector<ll> roots[200010];
    rep(i,0,N){
        roots[uf.root(i)].push_back(i);
    }
    rep(i,0,N){
        sort(roots[i].begin(), roots[i].end());
    }
    bool check[200010] = {};
    vector<lpair> lp;
    rep(i,0,N){
        if(roots[i].size() <= 1) continue;
        ll sz = roots[i].size();
        ll min_val = roots[i][0];
        ll max_val = roots[i][sz-1];
        lp.push_back({min_val, max_val});
    }
    sort(lp.begin(), lp.end());
    ll sz = lp.size();
    ll start = -1;
    ll ans = 0;
    rep(i,0,sz){
        ll s = lp[i].first, g = lp[i].second;
        s = max(s, start+1);
        rep(j,s,g+1){
            if(not uf.same(s, j)){
                ans++;
                uf.unite(s,j);
            }
        }
        start = max(start, g);
    }
    print(ans);


    

}