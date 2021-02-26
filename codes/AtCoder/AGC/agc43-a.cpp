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
    ll H,W;
    cin >> H >> W;
    string S[110];
    rep(i,0,H) cin >> S[i];
    ll dp[110][110] = {};
    rep(i,0,H+1){
        rep(j,0,W+1){
            dp[i][j] = INF;
        }
    }
    if(S[0][0] == '#'){
        dp[0][0] = 1;
    }else{
        dp[0][0] = 0;
    }

    rep(i,0,H){
        rep(j,0,W){
            if(i+1 < H){
                if(S[i][j] == '.' && S[i+1][j] == '#'){
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
                }else{
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                }
            }
            if(j+1 < W){
                if(S[i][j] == '.' && S[i][j+1] == '#'){
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
                }else{
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
                }             
            }

        }
    }
    print(dp[H-1][W-1]);
    

}