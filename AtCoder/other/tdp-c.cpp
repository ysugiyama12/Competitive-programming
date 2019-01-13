#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
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
double calc(double Rp, double Rq){
    double val = 0.0;
    double p = (Rq - Rp) / 400;
    val = 1 + pow(10, p);
    val = 1/val;
    return val;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    ll N = pow(2,K);
    double R[1100];
    rep(i,0,N){
        cin >> R[i];
    }
    double dp[1100][11] = {};
    rep(i,0,N){
        dp[i][0] = 1;
    }
    rep(j,1,K+1){
        rep(i,0,N){
            ll v = pow(2,j-1);
            if(v == 1){
                if(i % 2 == 0){
                    // cout << i << " " << i+1 << endl;
                    dp[i][j] = dp[i+1][j-1] * calc(R[i], R[i+1]);
                }else{
                    // cout << i << " " << i-1 << endl;
                    dp[i][j] = dp[i-1][j-1] * calc(R[i], R[i-1]);
                }

            }else{
                ll tt = i / v;
                // if(j == 2){
                //     print2("i= ",i);
                // }
                if(tt % 2 == 0){
                    rep(k,0,N){
                        if(k / v == tt+1){
                            // if(j == 2){
                            //     print(k);
                            // }
                            dp[i][j] += dp[i][j-1] * dp[k][j-1] * calc(R[i], R[k]);
                        }
                    }
                }else{
                    rep(k,0,N){
                        if(k / v == tt-1){
                            dp[i][j] += dp[i][j-1] * dp[k][j-1] * calc(R[i], R[k]);
                        }
                    }
                }

            }
        }
        // rep(k,0,N){
        //     print(dp[k][j]);
        // }
        // print("--");
    }
    rep(i,0,N){
        cout << setprecision(10) << dp[i][K] << endl;
    }
}
