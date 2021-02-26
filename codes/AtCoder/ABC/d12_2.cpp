
#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
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
    int N,M;
    ll a[50000], b[50000], t[50000];
    ll d[310][310];
    cin >> N >> M;
    rep(i,0,N){
        rep(j,0,N){
            d[i][j] = INF;
            if(i == j) d[i][j] = 0;
        }
    }
    rep(i,0,M){
        cin >> a[i] >> b[i] >> t[i];
        a[i]--; b[i]--;
        d[a[i]][b[i]] = t[i];
        d[b[i]][a[i]] = t[i];
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll ans = 1e12;
    rep(i,0,N){
        ll max_dist = 0;
        rep(j,0,N){
            max_dist = max(max_dist, d[i][j]);
        }
        ans = min(ans, max_dist);
    }
    print(ans);


}
