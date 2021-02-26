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
ll dist[200010] = {};
vector<ll> tree[200010];
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
    if(N == 1){
        print("First");
        return 0;
    }
    
    ll a[200010], b[200010];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    dfs(0, -1, 0);
    ll max_val = 0, max_pos = -1;
    rep(i,0,N){
        if(max_val < dist[i]){
            max_val = dist[i];
            max_pos = i;
        }
    }
    rep(i,0,N) dist[i] = 0;
    dfs(max_pos, -1, 0);
    max_val = 0;
    rep(i,0,N) max_val = max(max_val, dist[i]);
    if(max_val % 3 == 1){
        print("Second");
    }else{
        print("First");
    }



}