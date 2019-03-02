#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
vector<ll> tree[100010];
ll N;
ll p[100010];
ll parent[100010] = {};
ll subtree[100010] = {};
ll depth[100010] = {};
ll ans[100010] = {};
ll v = 0;
void dfs(ll cur, ll par, ll d){
    depth[cur] = d;
    ll cnt = 0;
    subtree[cur] = 1;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        cnt++;
        dfs(e, cur, d+1);
        subtree[cur] += subtree[e];
    }
    // if(cnt == 0){
    //     subtree[cur] = 1;
    // }
}

ll dfs2(ll cur, ll par){
    ll val = 0;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        val += dfs2(e, cur);
    }
    val += depth[cur];
    return val;
}

void dfs3(ll cur, ll par){
    ans[cur] = v;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        v  -= subtree[e];
        subtree[cur] -= subtree[e];
        v += subtree[cur];
        subtree[e] += subtree[cur];
        dfs3(e, cur);
        subtree[e] -= subtree[cur];
        v -= subtree[cur];
        subtree[cur] += subtree[e];
        v += subtree[e];
    }

    // ans[cur] = v;
    // ll sum = 0;
    // for(auto &e: tree[cur]){
    //     // if(e == par) continue;
    //     sum += subtree[e];
    // }
    // for(auto &e: tree[cur]){
    //     if(e == par) continue;
    //     v += sum - 2 * subtree[e] + 1;
    //     dfs3(e, cur);
    // }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> p[i];
        parent[i+1] = p[i];
        tree[p[i]].push_back(i+1);
    }
    dfs(0, -1, 0);
    // 9
    // 0 0 1 1 4 4 2 2
    v = dfs2(0, -1);
    dfs3(0, -1);
    rep(i,0,N) print(ans[i]);



}
