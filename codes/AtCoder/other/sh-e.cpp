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
ll N,M;
ll u[100010], v[100010], s[100010];
ll is_visit[100010] = {};
vector<lpair> tree[100010];

void dfs(ll cur, ll dist){
    if(is_visit[cur]) return;
    is_visit[cur] = 1;
    if(dist % 2 == 0){
        
    }
    for(auto &e: tree[cur]){
        dfs(e.first, dist+1);
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> u[i] >> v[i] >> s[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(make_pair(v[i], s[i]));
        tree[v[i]].push_back(make_pair(u[i], s[i]));
    }
    dfs(0, 0);

    
}