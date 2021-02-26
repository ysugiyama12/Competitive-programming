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
ll dist[100010] = {};

void dfs(ll cur, ll par, ll d){
    dist[cur] = d;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur, d+1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N-1){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0,-1,0);
    ll max_val = -1, max_pos = -1;
    rep(i,0,N){
        if(max_val < dist[i]){
            max_pos = i;
            max_val = dist[i];
        }
    }
    rep(i,0,N) dist[i] = 0;
    dfs(max_pos, -1, 0);
    max_val = -1;
    ll pos = -1;
    rep(i,0,N){
        if(max_val < dist[i]){
            max_val = dist[i];
            pos = i;
        }
    }
    print(max_pos+1, pos+1);

    

}