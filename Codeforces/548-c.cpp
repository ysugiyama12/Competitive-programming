#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

struct Combination{
private:
    ll N;
    vector<ll> fac, facinv;

public:
    Combination(ll n){
        N = n;
        fac.push_back(1); fac.push_back(1);
        rep(i,2,N+1) fac.push_back(fac[i-1] * i % MOD);
        rep(i,0,N+1) facinv.push_back(power(fac[i], MOD-2));
    }
    ll power(ll x, ll n){
        if(n == 0) return 1LL;
        ll res = power(x * x % MOD, n/2);
        if(n % 2 == 1) res = res * x % MOD;
        return res;
    }
    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
    }
    ll npk(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[n-k] % MOD;
    }
    ll get(ll x){return fac[x];};
    ll getinv(ll x){return facinv[x];};
};

struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
    }
    ll root(ll x){
        if(x == parent[x]) return x;
        else return parent[x] = root(parent[x]);
    }
    void unite(ll a, ll b){
        a = root(a); b = root(b);
        if(a == b) return;
        parent[a] = b;
        ll sum = num[a] + num[b];
        num[a] = sum;
        num[b] = sum;
    }
    bool same(ll a, ll b){ return root(a) == root(b);}
    ll sz(ll x){ return num[x];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    ll u[100010], v[100010], x[100010];
    cin >> N >> K;
    rep(i,0,N-1){
        cin >> u[i] >> v[i] >> x[i];
        u[i]--; v[i]--;
    }
    Combination cb(100010);
    UnionFind uf(100010);
    rep(i,0,N-1){
        if(x[i] == 0){
            uf.unite(u[i], v[i]);
        }
    }
    ll check[100010] = {};
    ll ans = cb.power(N, K);
    rep(i,0,N){
        ll v = uf.root(i);
        if(check[v] == 1) continue;
        check[v] = 1;
        ll sz = uf.sz(v);
        ans += (MOD - cb.power(sz, K)) % MOD;
        ans %= MOD;
    }
    print(ans);

    // dfs(0, -1);


    
}