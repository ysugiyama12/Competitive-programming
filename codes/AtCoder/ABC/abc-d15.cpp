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
ll dp[55][10010][55] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll W,N,K;
    cin >> W >> N >> K;
    ll A[55], B[55];
    rep(i,0,N){
        cin >> A[i] >> B[i];
    }
    rep(n,0,N){
        rep(w,0,W+1){
            rep(k,0,K){
                if(w - A[n] >= 0){
                    dp[n+1][w][k+1] = max(dp[n][w][k+1], dp[n][w-A[n]][k] + B[n]);
                }else{
                    dp[n+1][w][k+1] = dp[n][w][k+1];
                }
            }
        }
    }
    print(dp[N][W][K]);

}
