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
vector<ll> euler;
ll p_begin[100010] = {}, p_end[100010] = {};
ll idx = 0;

void dfs(ll cur, ll par){
    p_begin[cur] = idx;
    euler.push_back(cur);
    idx++;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
        euler.push_back(cur);
        idx++;
    }
    p_end[cur] = idx;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q;
    cin >> N >> Q;
    rep(i,1,N){
        ll p;
        cin >> p;
        p--;
        tree[i].push_back(p);
        tree[p].push_back(i);
    }
    char c[100010];
    rep(i,0,N) cin >> c[i];
    dfs(0,-1);
    printa(euler, euler.size());
    print(p_begin[1], p_end[1]);
    while(Q--){
        ll v;
        cin >> v;
        v--;
    }


    

}