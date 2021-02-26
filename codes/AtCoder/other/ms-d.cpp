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
vector<ll> tree[10010];
ll val[10010] = {};
ll idx = 0;
ll c[10010];
void dfs(ll cur, ll par){
    val[cur] = c[idx];
    idx++;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[10010], b[10010];
    
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    rep(i,0,N) cin >> c[i];
    sort(c, c+N, greater<ll>());
    ll ans = 0;
    rep(i,1,N) ans += c[i];
    dfs(0, -1);
    print(ans);
    printa(val, N);




    
}