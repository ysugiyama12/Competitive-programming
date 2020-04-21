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
vector<ll> tree[100010];
ll dp[100010] = {};
ll val[100010] = {};
ll res[100010] = {};
void dfs(ll cur, ll par){
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
        dp[cur] += dp[e];
    }
    dp[cur] += val[cur];

    return;
}

void dfs2(ll cur, ll par){
    if(cur == 0){
        res[cur] = 0;
    }else{
        res[cur] = res[par] - dp[cur];
    }
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs2(e, cur);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll u[100010], v[100010];
    rep(i,0,N-1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
    }
    ll a[100010], b[100010];
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];
    rep(i,0,N) val[i] = b[i] - a[i];
    // printa(val, N);
    dfs(0, -1);
    dfs2(0, -1);
    // printa(res, N);
    // printa(dp, N);
    ll min_val = INF;
    rep(i,0,N){
        min_val = min(min_val, res[i]);
    }
    ll ans = 0;
    rep(i,0,N){
        ans += res[i] - min_val;
    }

    print(ans);
    

}