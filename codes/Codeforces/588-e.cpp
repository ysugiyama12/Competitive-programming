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
ll x[100010];
vector<ll> tree[100010];
map<ll, ll> mp[100010];
ll ans = 0;
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void dfs(ll cur, ll par){
    if(par == -1){
        mp[cur][x[cur]]++;
        ans += x[cur];
        ans %= MOD;
    }else{
        mp[cur][x[cur]]++;
        ans += x[cur];
        ans %= MOD;
        for(auto &e: mp[par]){
            mp[cur][gcd(e.first, x[cur])] += e.second;
            ans += gcd(e.first, x[cur]) * e.second;
            ans %= MOD;
        }
    }

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
    rep(i,0,N) cin >> x[i];
    ll a[100010], b[100010];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    dfs(0, -1);
    print(ans);
}