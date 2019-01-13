#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

typedef struct{
    ll to;
    ll cost;
} edge;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    ll a[50000], b[50000], t[50000];
    cin >> N >> M;
    vector<edge> tree[310];
    rep(i,0,M){
        cin >> a[i] >> b[i] >> t[i];
        a[i]--; b[i]--;
        edge e = {b[i], t[i]};
        tree[a[i]].push_back(e);
        edge e2 = {a[i], t[i]};
        tree[b[i]].push_back(e2);
    }
    ll dist[310];
    bool is_visit[310];
    ll ans = 1e18;
    rep(s,0,N){
        rep(i,0,N){
            dist[i] = 1e18;
            is_visit[i] = false;
        }
        dist[s] = 0;
        priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > > qq;
        rep(i,0,N){
            qq.push(make_pair(dist[i], i));
        }
        while(!qq.empty()){
            auto tt = qq.top();
            qq.pop();
            is_visit[tt.second] = true;
            for(auto &e : tree[tt.second]){
                if(dist[e.to] > dist[tt.second] + e.cost){
                    if(!is_visit[e.to]){
                        dist[e.to] = dist[tt.second] + e.cost;
                        qq.push(make_pair(dist[e.to], e.to));

                    }
                }
            }


        }
        ll max_dist = 0;
        rep(i,0,N){
            max_dist = max(max_dist, dist[i]);
        }
        ans = min(ans, max_dist);

    }
    print(ans);


}
