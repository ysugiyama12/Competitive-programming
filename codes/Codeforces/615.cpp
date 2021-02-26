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
ll dist[200010] = {};
void dfs(ll cur, ll par, ll d){
    dist[cur] = d;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur, d+1);
    }
}
bool vertex[200010] = {};
bool dfs2(ll cur, ll par, ll target){
    bool flg = false;
    for(auto &e: tree[cur]){
        if(e == par ) continue;
        flg |= dfs2(e, cur, target);
    }
    if(cur == target){
        flg = true;
    }
    if(flg) vertex[cur] = true;
    return flg;

}

struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;
    vector<ll> diff_weight;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
        rep(i,0,N) diff_weight.push_back(0);
    }

    ll root(ll x){
        if(x == parent[x]){
            return x;
        }else{
            ll r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }

    void unite(ll a, ll b, ll w = 0){
        w += weight(a); w -= weight(b);
        a = root(a); b = root(b);
        if(a == b) return;
        parent[b] = a;
        ll sum = num[a] + num[b];
        num[a] = sum;
        num[b] = sum;
        diff_weight[b] = w;
    }

    bool same(ll a, ll b){ return root(a) == root(b);}
    
    ll sz(ll x){ return num[root(x)];}

    ll weight(ll x){
        root(x);
        return diff_weight[x];
    }

    ll diff(ll a, ll b){
        return weight(b) - weight(a);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[200010], b[200010];

    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    dfs(0,-1,0);
    ll idx = -1, mv = -1;
    rep(i,0,N){
        if(mv < dist[i]){
            mv = dist[i];
            idx = i;
        }
    }
    rep(i,0,N) dist[i] = 0;
    dfs(idx, -1, 0);
    ll idx2 = 0;
    mv = -1;
    rep(i,0,N){
        if(mv < dist[i]){
            mv = dist[i];
            idx2 = i;
        }
    }
    // print(idx, idx2);
    bool res = dfs2(idx, -1, idx2);
    ll dd[200010] = {};
    rep(i,0,N) dd[i] = INF;
    queue<lpair> que;
    rep(i,0,N){
        if(vertex[i]) que.push({i, 0});
    }

    while(not que.empty()){
        lpair l1 = que.front();
        que.pop();
        if(dd[l1.first] != INF) continue;
        dd[l1.first] = l1.second;
        for(auto &e: tree[l1.first]){
            if(dd[e] == INF){
                que.push({e, l1.second+1});
            }
        }
    }
    // printa(dd, N);
    ll ans = 0, max_val = 0, max_idx = 0;
    rep(i,0,N){
        if(dd[i] == 0) ans++;
        if(max_val < dd[i]){
            max_val = dd[i];
            max_idx = i;
        }
    }
    ans += max_val;
    print(ans-1);
    while(max_idx == idx || max_idx == idx2) max_idx++;
    print(idx+1, idx2+1, max_idx+1);




    

}