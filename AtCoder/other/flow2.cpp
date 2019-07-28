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
typedef struct {
    ll to;
    ll cap;
    ll rev;
} edge;
vector<edge> G[210];
bool used[210];

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
    ll X,Y,E;
    cin >> X >> Y >> E;
    ll x[10010], y[10010];
    rep(i,0,E){
        cin >> x[i] >> y[i];
        x[i]++; y[i] += X+1;
        G[x[i]].push_back((edge){y[i], 1, G[y[i]].size()});
        G[y[i]].push_back((edge){x[i], 0, G[x[i]].size()-1});
    }
    rep(i,1,X+1){
        G[0].push_back((edge){i, 1, G[i].size()});
        G[i].push_back((edge){0, 0, G[0].size()-1});        
    }
    rep(i,X+1,X+Y+1){
        G[i].push_back((edge){X+Y+1, 1, G[X+Y+1].size()});
        G[X+Y+1].push_back((edge){i, 0, G[i].size()-1});
    }

    ll ans = 0;
    while(1){
        memset(used, 0, sizeof(used));
        ll f = dfs(0, X+Y+1, INF);
        if(f == 0) break;
        ans += f;
    }
    print(ans);
    
}