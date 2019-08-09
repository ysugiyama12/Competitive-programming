/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll dp[1010][1010][3][2] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    string S[1010];
    rep(i,0,M) cin >> S[i];
    dp[0][0][0][0] = 1;
    rep(i,0,N){
        rep(l,0,M+1){
            rep(k,0,3){
                rep(j,0,10){
                    if(j % 5 == 0) continue;
                    if((k + j) % 3 != 0){
                        (dp[i+1][l][(k+j) % 3][1] += dp[i][l][k][1]) %= MOD;
                        (dp[i+1][l][(k+j) % 3][1] += dp[i][l][k][0]) %= MOD;
                    }
                }
            }
            if(l == 0) continue;
            if(S[l-1] == "Fizz"){
                rep(k,0,3){
                    ll s = (3 - k) % 3;
                    for(ll v = s; v < 10; v += 3){
                        if(v % 5 == 0) continue;
                        (dp[i+1][l][0][1] += dp[i][l-1][k][1]) %= MOD;
                        (dp[i+1][l][0][1] += dp[i][l-1][k][0]) %= MOD;
                    }
                }

            }else if(S[l-1] == "Buzz"){
                rep(k,0,3){
                    if(k % 3 != 0){
                        (dp[i+1][l][k][1] += dp[i][l-1][k][1]) %= MOD;   
                    }
                    if(k % 3 != 1){
                        (dp[i+1][l][(k+5)%3][1] += dp[i][l-1][k][1]) %= MOD;
                        (dp[i+1][l][(k+5)%3][1] += dp[i][l-1][k][0]) %= MOD;              
                    }
                }
            }else{
                // 0
                (dp[i+1][l][0][1] += dp[i][l-1][0][1]) %= MOD;
                // 5
                (dp[i+1][l][0][1] += dp[i][l-1][1][1]) %= MOD;
                (dp[i+1][l][0][1] += dp[i][l-1][1][0]) %= MOD;

            }


        }
    }
    ll ans = 0;
    rep(k,0,3){
        ans += dp[N][M][k][1];
        ans %= MOD;
    }
    print(ans);

    
}