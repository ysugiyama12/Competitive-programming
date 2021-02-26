/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X,Y;
    cin >> X >> Y;
    ll N;
    cin >> N;
    ll t[310], h[310];
    rep(i,0,N) cin >> t[i] >> h[i];
    ll K = min(X, N);
    ll dp[2][610][310] = {};
    rep(i,0,2){
        rep(j,0,610){
            rep(k,0,310){
                dp[i][j][k] = -1;
            }
        }
    }
    dp[0][0][0] = 0;
    ll pos = 1;
    rep(i,0,N){
        rrep(k,K,0){
            rrep(j,X+Y,0){
                if(j - t[i] >= 0){
                    if(k != 0){
                        if(dp[pos^1][j-t[i]][k-1] == -1){
                            dp[pos][j][k] = -1;
                        }else{
                            dp[pos][j][k] = dp[pos^1][j-t[i]][k-1] + h[i];
                        }
                    }
                }
                if(dp[pos^1][j][k] == -1) continue;
                dp[pos][j][k] = max(dp[pos][j][k], dp[pos^1][j][k]);
            }
        }
        // print(dp[pos][5][1]);
        pos ^= 1;
    }
    pos ^= 1;
    // print(dp[pos][8][2]);
    ll ans = 0;
    rep(i,0,K+1){
        rep(j,0,X+Y+1){
            ans = max(ans, dp[pos][j][i]);

        }
    }
    print(ans);
    // rep(n,1,N+1){
    //     if(X < n) break;
    //     ll xy = X - n + Y;
    //     ll dp[2][610] = {};
    //     dp[0][0] = 0;
    //     ll pos = 0;
    //     rep(i,0,N){
    //         pos = (i % 2 == 0 ? 1 : 0);
    //         rrep(j,xy,0){
    //             if(j - t[i] >= 0){
    //                 dp[pos][j] = max(dp[pos^1][j], dp[pos^1][j-t[i]] + h[i]);
    //             }

    //         }
    //     }
    // }


}