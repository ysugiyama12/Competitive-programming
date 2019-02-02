#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll dp[100010][310] = {};
ll dp2[310][310][31] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,K;
    ll A[100010];
    cin >> N >> M >> K;
    rep(i,0,N) cin >> A[i];
    if(M != N){
        rep(i,0,N){
            rep(k,0,K){
                if(i < k) continue;
                dp[i+1][k+1] = max(dp[i][k+1], dp[i][k] + (k+1) * A[i]);
            }
        }
        print(dp[N][K]);
    }else if(N <= 300 && K <= 30){
        rep(i,0,N){
            rep(j,0,N){
                rep(k,0,K){
                    if(i < k) continue;
                    if(k == 0){
                        dp2[i+1][i+1][k+1] = A[i];
                    }else{
                        if(i - j >= 1 && i - j <= M){
                            dp2[i+1][i]
                        }


                    }
                }
            }
        }

    }
}