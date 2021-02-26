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
typedef struct{
    ll to;
    ll cap;
    ll rev;
} edge;
vector<edge> G[110];
bool used[110];

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
    ll n,g,e;
    cin >> n >> g >> e;
    ll p[110], a[10010], b[10010];
    rep(i,0,g) cin >> p[i];
    rep(i,0,e){
        cin >> a[i] >> b[i];
        G[b[i]].push_back((edge){a[i], 1, G[a[i]].size()});
        G[a[i]].push_back((edge){b[i], 0, G[b[i]].size()-1});
        G[a[i]].push_back((edge){b[i], 1, G[b[i]].size()});
        G[b[i]].push_back((edge){a[i], 0, G[a[i]].size()-1});
    }
    rep(i,0,g){
        G[p[i]].push_back((edge){n, 1, G[n].size()});
        G[n].push_back((edge){p[i], 0, G[p[i]].size()-1});
    }

    ll ans = 0;
    while(1){
        memset(used, 0, sizeof(used));
        ll f = dfs(0, n, INF);
        if(f == 0) break;
        ans += f;
    }
    print(ans);
    
}