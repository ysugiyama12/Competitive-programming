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
ll dp[45][510][510];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Ma,Mb;
    ll a[50], b[50], c[50];
    cin >> N >> Ma >> Mb;
    rep(i,0,N){
        cin >> a[i] >> b[i] >> c[i];
    }
    rep(i,0,N){
        rep(j,0,500){
            rep(k,0,500){
                dp[i][j][k] = 1e9;
            }
        }
    }
    dp[0][0][0] = 0;
    rep(i,0,N){
        rep(j,0,500){
            rep(k,0,500){
                if(j >= a[i] && k >= b[i]){
                    dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a[i]][k-b[i]] + c[i]);
                }else{
                    dp[i+1][j][k] = dp[i][j][k];
                }

            }
        }
    }
    ll ans = 1e9;
    rep(i,0,500){
        rep(j,0,500){
            if((i != 0 || j != 0) && i * Mb == j * Ma){
                ans = min(ans, dp[N][i][j]);
            }

        }
    }
    if(ans == 1e9){
        print(-1);
    }else{
        print(ans);
    }
}
