#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
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
int N,M;
ll a[2010], b[2010], c[2010];
vector<edge> tree[2010];
ll dist[2010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        c[i] *= -1;
        edge ed = {b[i], c[i]};
        tree[a[i]].push_back(ed);
    }
    rep(i,0,N){
        dist[i] = 1e18;
    }
    dist[0] = 0;
    rep(i,0,N-1){
        rep(j,0,M){
            if(dist[a[j]] == 1e18) continue;
            if(dist[b[j]] > dist[a[j]] + c[j]){
                dist[b[j]] = dist[a[j]] + c[j];
            }
        }
    }
    rep(i,0,N-1){
        rep(j,0,M){
            if(dist[a[j]] == 1e18) continue;
            if(dist[b[j]] > dist[a[j]] + c[j]){
                dist[b[j]] = dist[a[j]] + c[j];
            }
        }
    }
    bool is_negative[2010];
    rep(i,0,N){
        is_negative[i] = false;
    }
    rep(i,0,N){
        rep(j,0,M){
            if(dist[a[j]] == 1e18) continue;
            if(dist[b[j]] > dist[a[j]] + c[j]){
                dist[b[j]] = dist[a[j]] + c[j];
                is_negative[b[j]] = true;
            }
            if(is_negative[a[j]]){
                is_negative[b[j]] = true;
            }
        }
    }
    if(is_negative[N-1]){
        print("inf");
    }else{
        print(-dist[N-1]);
    }







}
