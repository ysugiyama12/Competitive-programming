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
ll depth[100010] = {};
vector<ll> tree[100010];

void dfs(ll cur, ll par, ll d){
    depth[cur] = d;
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

    ll a[100010], b[100010];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    dfs(0,-1, 0);
    ll max_val = N-1, min_val = 0;
    ll leaf_cnt[100010] = {};
    vector<ll> p;
    rep(i,0,N){
        if(tree[i].size() == 1){
            leaf_cnt[tree[i][0]]++;
            p.push_back(tree[i][0]);
        }
    }
    p.erase(unique(p.begin(), p.end()), p.end());
    ll sz = p.size();
    ll num = 0;
    for(auto &e: p){
        if(depth[e] % 2 == 0){
            num++;
        }
    }
    if(num == sz || num == 0){
        min_val = 1;
    }else{
        min_val = 3;
    }
    rep(i,0,N){
        if(leaf_cnt[i] > 1){
            max_val -= leaf_cnt[i]-1;
        }
    }
    print(min_val, max_val);


    

}