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
vector<ll> tree[200010];
ll child[200010] = {};
ll color[200010] = {};
ll ans = 0;
ll depth[200010] = {};
ll val[200010] = {};

void dfs(ll cur, ll par, ll d){
    depth[cur] = d;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur, d+1);
        child[cur] += child[e];
    }
    child[cur]++;
}

void dfs2(ll cur, ll par){
    if(cur != 0){
        if(color[cur] == 1) ans += val[par];
        if(color[cur] == 0){
            val[cur] = val[par] + 1;
        }else{
            val[cur] = val[par];
        }
    }else{
        if(color[cur] == 0){
            val[cur]++;
        }
    }

    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs2(e, cur);
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll u[200010], v[200010];
    rep(i,0,N-1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
    }
    dfs(0, -1, 0);
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back({depth[i] - child[i]-1, i});
    }

    sort(lp.begin(), lp.end(), greater<lpair>());
    rep(i,0,K){
        color[lp[i].second] = 1;
    }
    dfs2(0, -1);
    print(ans);




    

}