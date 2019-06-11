#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
ll N;
ll u[200010], v[200010];
vector<ll> tree[200010];
ll ans = 0;


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

Combination cb(200010);


void dfs2(ll cur, ll par){
    ll v = tree[cur].size();
    ans *= cb.get(v);
    ans %= MOD;
    // print(ans);
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs2(e, cur);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
    }

    ans = N;
    dfs2(0, -1);
    print(ans);






    
}