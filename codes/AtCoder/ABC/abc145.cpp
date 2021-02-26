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
ll dp[310][310][310] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll H[310];
    H[0] = 0;
    rep(i,0,N) cin >> H[i+1];
    // vector<ll> v;
    // rep(i,0,N) v.push_back(H[i]);
    // v.push_back(0);
    // sort(v.begin(), v.end());
    rep(i,0,N+1){
        rep(j,0,K+1){
            rep(k,0,N+2){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    // rep(i,0,N+1){
    //     if(H[0] == v[i]){
    //         dp[1][0][i] = v[i];
    //     }else{
    //         dp[1][0][i] = INF;
    //     }
    // }
    // rep(i,0,N+1) dp[1][1][i] = 0;

    rep(i,0,N){ // i番目まで見てすでにj回操作した 最後の高さがv[k]
        rep(j,0,K+1){
            rep(k,0,N+1){
                if(dp[i][j][k] == INF) continue;
                // print(i,j,k);
                // 操作しない
                if(H[k] >= H[i+1]){
                    dp[i+1][j][i+1] = min(dp[i+1][j][i+1], dp[i][j][k]);
                }else{
                    dp[i+1][j][i+1] = min(dp[i+1][j][i+1], dp[i][j][k] + H[i+1] - H[k]);
                }
                // 操作する
                if(j == K) continue;
                dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);             
            }
        }
    }
    // print(dp[3][1][1]); // 2 0 2 => 3 1 3
    // print(dp[4][1][4]);
    ll ans = INF;
    rep(h,0,N+1){
        ans = min(ans, dp[N][K][h]);
    }
    print(ans);
    

}
