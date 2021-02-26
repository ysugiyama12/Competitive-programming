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
ll child[100010] = {};
ll ans[100010] = {};
void dfs(ll cur, ll par){
    bool ok = false;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        ok = true;
        dfs(e, cur);
        child[cur] += child[e];
    }
    child[cur]++;
}

void dfs2(ll cur, ll par){
    ll max_val = 0;
    for(auto &e: tree[cur]){
        max_val = max(max_val, child[e]);
    }
    ans[cur] = max_val;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        child[cur] -= child[e];
        if(par != -1) child[cur] += child[par];
        dfs2(e, cur);
        if(par != -1) child[cur] -= child[par];
        child[cur] += child[e];
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll p[100010];
    rep(i,0,N-1){
        cin >> p[i];
        tree[i+1].push_back(p[i]);
        tree[p[i]].push_back(i+1);
    }
    dfs(0, -1);
    dfs2(0, -1);
    rep(i,0,N) print(ans[i]);
    

}