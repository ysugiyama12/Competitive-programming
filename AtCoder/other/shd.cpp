#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
#define mp make_pair
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
const ll INF15 = (ll)1e15;

using namespace std;
const int N = 100010;
ll dist[N]; //distance from start point
ll dist_tmp[N];
vector< pair<ll, int> > g[N];
vector< pair<ll, int> > G[N];

void dijkstra(int start){
    set<pair<ll, int> > setik;
    rep(i,0,N){
        dist[i] = INF15;
        if (i == start) dist[i] = 0; //start point
        setik.insert(mp(dist[i], i));
    }

    while(!setik.empty()) {
        start = setik.begin()->second;
        setik.erase(setik.begin());
        for(pair<ll, int> e : g[start]){
            int t = e.second;
            ll w = dist[start] + e.first;
            if(w >= dist[t]) continue;

            setik.erase(mp(dist[t], t));
            dist[t] = w;
            setik.insert(mp(dist[t], t));
        }


    }



    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    s--; t--;
    int u[N], v[N];
    ll a[N], b[N];
    rep(i,0,m){
        cin >> u[i] >> v[i] >> a[i] >> b[i];
    }
    rep(i,0,m){
        u[i]--; v[i]--;
        g[v[i]].push_back(mp(a[i], u[i]));
        G[v[i]].push_back(mp(b[i], u[i]));

        g[u[i]].push_back(mp(a[i], v[i]));
        G[u[i]].push_back(mp(b[i], v[i]));
    }
    print("hey");
    dijkstra(s);
    print("hey");

    swap(dist, dist_tmp);
    swap(g,G);
    dijkstra(t);
    print("hey");
    ll ans[N];
    rep(i,0,n){
        ans[i] = dist_tmp[i] + dist[i];
    }
    for(int i = n-2; i >= 0; i--){
        ans[i] = min(ans[i], ans[i+1]);
    }
    rep(i,0,n){
        ll aa = INF15 - ans[i];
        print(aa);
    }



}
