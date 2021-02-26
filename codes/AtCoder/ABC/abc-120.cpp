#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

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

// const ll max_N = 100000;
// ll fac[max_N + 10], facinv[max_N + 10];

// ll power(ll x, ll n){ // xのn乗 % MOD
//     if(n == 0) return 1LL;
//     ll res = power(x * x % MOD, n/2);
//     if(n % 2 == 1) res = res * x % MOD;
//     return res;
// }

// ll nck(ll n, ll k){
//     if(k == 0 || n == k) return 1;
//     return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
// }

// ll npk(ll n, ll k){
//     if(k == 0 || n == k) return 1;
//     return fac[n] * facinv[n-k] % MOD;
// }

// void comb_setup(){
//     fac[0] = 1; fac[1] = 1;
//     rep(i,2,max_N+1) fac[i] = (fac[i-1] * i) % MOD;
//     rep(i,0,max_N+1) facinv[i] = power(fac[i], MOD - 2);
// }
int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination cb(100010);
    print(cb.nck(10000,9999));
    // ll N,M;
    // cin >> N >> M;
    // ll A[100010], B[100010];
    // rep(i,0,M){
    //     cin >> A[i] >> B[i];
    //     A[i]--; B[i]--;
    // }
    // UnionFind uf(100010);
    // ll v = N*(N-1)/2;
    // vector<ll> ans;
    // ans.push_back(v);
    // rrep(i,M-1,0){
    //     if(uf.same(A[i], B[i])){
    //         ans.push_back(v);
    //     }else{
    //         v -= uf.sz(uf.root(A[i])) * uf.sz(uf.root(B[i]));
    //         uf.unite(A[i], B[i]);
    //         ans.push_back(v);
    //     }
    // }
    // rrep(i,M-1,0){
    //     print(ans[i]);
    // }
}
