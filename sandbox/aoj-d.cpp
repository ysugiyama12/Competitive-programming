/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
vector<ll> tree[100010];
ll a[100010], b[100010], w[100010];
ll N, T, S, E;
ll parent[100010] = {};
bool path[100010] = {};
bool ok = true;
map<lpair, ll> is_once;
map<lpair, ll> weight;

void dfs(ll cur, ll par){
    parent[cur] = par;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
    }
}

void dfs2(ll cur, ll par){
    vector<ll> edge;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        if(is_once[make_pair(cur, e)]) continue;
        ll ww = weight[make_pair(cur, e)];
        ww -= T * (ll)(tree[e].size());
        edge.push_back(ww);
    }
    sort(edge.begin(), edge.end());
    ll sz = edge.size();
    rep(i,0,sz){
        ll val = edge[i] - T * (i+1);
        if(cur == S) val += T;
        if(val <= 0) ok = false;
    }
    for(auto &e: tree[cur]){
        if(e == par) continue;
        if(is_once[make_pair(cur, e)]){
            // print2(cur, e);
            ll val = weight[make_pair(cur, e)] - T * (sz + 1);
            if(cur == S) val += T;
            if(val <= 0){
                ok = false;
            }
        }
    }
    for(auto &e : tree[cur]){
        if(e == par) continue;
        dfs2(e, cur);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> T >> S >> E;
    S--; E--; 
    rep(i,0,N-1){
        cin >> a[i] >> b[i] >> w[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
        weight[make_pair(a[i], b[i])] = w[i];
        weight[make_pair(b[i], a[i])] = w[i];
    }
    dfs(S, -1);
    ll p = E;
    while(p != -1){
        if(parent[p] == -1) break;
        is_once[make_pair(p, parent[p])]++;
        is_once[make_pair(parent[p], p)]++;
        // print2(p, parent[p]);
        p = parent[p];
        
    }
    dfs2(S, -1);
    if(ok){
        print("Yes");
    }else{
        print("No");
    }







    
}