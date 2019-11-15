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
ll x[100010], y[100010];
UnionFind uf(200010);
ll cnt_path[200010] = {};
set<ll> cnt_x[200010], cnt_y[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    rep(i,0,N){
        uf.unite(x[i], y[i]+100000);
    }
    rep(i,0,N){
        ll rt = uf.root(x[i]);
        cnt_path[rt]++;
        cnt_x[rt].insert(x[i]);
        cnt_y[rt].insert(y[i]);
    }
    ll ans = 0;
    bool check[200010] = {};
    rep(i,0,N){
        ll rt = uf.root(x[i]);
        if(check[rt]) continue;
        check[rt] = true;
        ll nx = cnt_x[rt].size();
        ll ny = cnt_y[rt].size();
        ll nc = cnt_path[rt];
        ans += nx * ny - nc;
    }
    print(ans);
}