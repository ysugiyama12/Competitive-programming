#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll N,M,T;
ll A[100010], a[100010], b[100010], c[100010];
vector<edge> tree[100010];
vector<edge> tree_inv[100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> T;
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        edge e = {b[i],c[i]};
        tree[a[i]].push_back(e);
        edge e2 = {a[i],c[i]};
        tree_inv[b[i]].push_back(e2);
    }
    ll dist[100010] = {};
    ll is_visit[100010] = {};
    rep(i,1,N){
        dist[i] = INF;
    }
    priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > > pq;
    rep(i,0,N){
        pq.push(make_pair(dist[i],i));
    }
    while(!pq.empty()){
        auto tt = pq.top();
        pq.pop();
        is_visit[tt.second] = 1;
        for(auto &e : tree[tt.second]){
            if(dist[e.to] > dist[tt.second] + e.cost){
                if(!is_visit[e.to]){
                    dist[e.to] = dist[tt.second] + e.cost;
                    pq.push(make_pair(dist[e.to], e.to));
                }
            }
        }
    }
    ll dist_inv[100010] = {};
    rep(i,1,N){
        dist_inv[i] = INF;
    }
    rep(i,0,N){
        is_visit[i] = 0;
    }
    priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > > pq_inv;
    rep(i,0,N){
        pq_inv.push(make_pair(dist_inv[i],i));
    }
    while(!pq_inv.empty()){
        auto tt = pq_inv.top();
        pq_inv.pop();
        is_visit[tt.second] = 1;
        for(auto &e : tree_inv[tt.second]){
            if(dist_inv[e.to] > dist_inv[tt.second] + e.cost){
                if(!is_visit[e.to]){
                    dist_inv[e.to] = dist_inv[tt.second] + e.cost;
                    pq_inv.push(make_pair(dist_inv[e.to], e.to));
                }
            }
        }
    }
    // ll dist[1010][1010] = {};
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(i == j){
    //             dist[i][j] = 0;
    //         }else{
    //             dist[i][j] = INF;
    //         }
    //     }
    // }

    // rep(i,0,M){
    //     dist[a[i]][b[i]] = c[i];
    // }
    // rep(k,0,N){
    //     rep(i,0,N){
    //         rep(j,0,N){
    //             dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    //         }
    //     }
    // }
    ll ans = 0;
    rep(i,0,N){
        ll t1 = dist[i];
        ll t2 = dist_inv[i];
        ll t_stay = T - t1 - t2;
        if(t_stay <= 0) continue;
        ans = max(ans, A[i] * t_stay);
    }
    print(ans);

}
