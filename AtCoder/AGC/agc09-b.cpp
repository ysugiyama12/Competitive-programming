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
ll val[100010] = {};

void dfs(ll cur, ll par){
    ll cnt = 0;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        cnt++;
        dfs(e, cur);
    }
    if(cnt == 0){
        val[cur] = 0;
        return;
    }
    ll min_val = INF, max_val = -INF;
    vector<ll> v;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        v.push_back(val[e]);
    }
    sort(v.begin(), v.end());
    rep(i,0,v.size()){
        val[cur] = max(val[cur], v[i] + cnt-i);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[100010];
    rep(i,0,N-1){
        cin >> a[i];
        a[i]--;
        tree[a[i]].push_back(i+1);
    }
    dfs(0, -1);
    print(val[0]);
    

}