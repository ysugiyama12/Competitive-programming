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
    ll N,M;
    ll a[1010], b[1010], c[1010];
    ll wa[110][110] = {};
    cin >> N >> M;
    rep(i,0,N){
        rep(j,0,N){
            wa[i][j] = 1e9;
            if(i == j){
                wa[i][j] = 0;
            }
        }
    }
    rep(i,0,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        wa[a[i]][b[i]] = c[i];
        wa[b[i]][a[i]] = c[i];
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                wa[i][j] = min(wa[i][j], wa[i][k] + wa[k][j]);
            }
        }
    }
    bool is_pass[1010];
    rep(i,0,M){
        is_pass[i] = false;
    }
    rep(i,0,N){
        rep(j,0,N){
            if(i != j){
                rep(k,0,M){
                    if(wa[i][j] == wa[i][a[k]] + c[k] + wa[b[k]][j]){
                        is_pass[k] = true;
                    }
                }
            }
        }

    }
    ll ans = 0;
    rep(i,0,M){
        if(!is_pass[i]) ans++;
    }
    print(ans);
}
