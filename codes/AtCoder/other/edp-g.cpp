#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll N,M;
ll x[100010], y[100010];
vector<ll> tree[100010];
// ll h[100010] = {}; 
ll dp[100010] = {};
ll dfs(ll cur){
    ll &res = dp[cur];
    if(~res) return res;
    res = 0;
    for(auto &e: tree[cur]){
        res = max(res, dfs(e) + 1);
    }
    return res;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        tree[x[i]].push_back(y[i]);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    rep(i,0,N){
        ans = max(ans, dfs(i));
    }
    print(ans);
    // printa(dp,N);
    // print(ans);
    // rep(i,0,M){
    //     cin >> x[i] >> y[i];
    //     x[i]--; y[i]--;
    //     tree[x[i]].push_back(y[i]);
    //     h[y[i]]++;
    // }
    // stack<ll> st;
    // rep(i,0,N){
    //     if(h[i] == 0){
    //         st.push(i);
    //     }
    // }
    // vector<ll> ans;
    // while(st.size()){
    //     ll k = st.top();
    //     st.pop();
    //     ans.push_back(k);
    //     for(auto &e: tree[k]){
    //         h[e]--;
    //         if(h[e] == 0) st.push(e);
    //     }
    // }
    // rep(i,0,N){
    //     ll v = ans[i];
    //     for(auto &e : tree[v]){
    //         d[e] = max(d[e], d[v] + 1);
    //     }
    // }
    // ll val = 0;
    // rep(i,0,N){
    //     val = max(val, d[i]);
    // }
    // print(val);

}
