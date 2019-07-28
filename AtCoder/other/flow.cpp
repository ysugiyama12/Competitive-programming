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
typedef struct{
    ll to;
    ll cap;
    ll rev;
} edge;
vector<edge> G[1010];
bool used[1010];

ll dfs(ll v, ll t, ll f){
    if(v == t) return f;
    used[v] = true;
    rep(i,0,G[v].size()){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        ll u,v,c;
        cin >> u >> v >> c;
        G[u].push_back((edge){v, c, G[v].size()});
        G[v].push_back((edge){u, 0, G[u].size() - 1});
    }
    ll ans = 0;
    while(1){
        memset(used, 0, sizeof(used));
        ll f = dfs(0, N-1, INF);
        if(f == 0) break;
        ans += f;
    }
    print(ans);

    
}