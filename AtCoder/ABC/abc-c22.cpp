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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll u[100010], v[100010], l[100010];
    cin >> N >> M;
    rep(i,0,M){
        cin >> u[i] >> v[i] >> l[i];
        u[i]--; v[i]--;
    }
    ll d[310][310] = {};
    rep(i,0,N){
        rep(j,0,N){
            if(i == j){
                d[i][j] = 0;
            }else{
                d[i][j] = INF;
            }
        }
    }
    vector<ll> conn;
    rep(i,0,M){
        if(u[i] != 0){
            d[u[i]][v[i]] = l[i];
            d[v[i]][u[i]] = l[i];
        }else{
            conn.push_back(i);
        }
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll n = conn.size();
    ll ans = INF;
    rep(i,0,n){
        rep(j,0,n){
            if(i != j){
                ll v1 = conn[i];
                ll v2 = conn[j];
                ll dist = d[v[v1]][v[v2]];
                ans = min(ans, dist + l[v1] + l[v2]);
            }
        }
    }
    if(ans >= 1e12){
        print(-1);
    }else{
        print(ans);
    }


}
