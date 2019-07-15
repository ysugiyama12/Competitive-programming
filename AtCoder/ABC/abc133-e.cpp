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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
vector<ll> tree[100010];
ll parent[100010] = {};
ll cnt[100010] = {};
ll val[100010] = {};
ll N,K;
void dfs(ll cur, ll par){
    if(par == -1){
        val[cur] = K;
    }else if(par == 0){
        val[cur] = K - 1 - cnt[par];
        cnt[par]++;
    }else{
        val[cur] = K - 2 - cnt[par];
        cnt[par]++;
    }
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    ll a[100010], b[100010];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(a[i] > b[i]) swap(a[i], b[i]);
        parent[b[i]] = a[i];
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    parent[0] = -1;
    dfs(0,-1);
    ll ans = 1;
    rep(i,0,N){
        ans *= val[i];
        ans %= MOD;
    }
    print(ans);
    
}