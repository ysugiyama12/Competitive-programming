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
int A[81][81], B[81][81];
bool dp[81][81][80*80*2+5] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W;
    cin >> H >> W;
    rep(i,0,H){
        rep(j,0,W){
            cin >> A[i][j];
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            cin >> B[i][j];
        }
    }
    ll thre = 80*80;
    ll v = abs(A[0][0] - B[0][0]);
    dp[0][0][thre + v] = 1;
    rep(i,0,H){
        rep(j,0,W){
            rep(k,0,80*80*2+2){
                if(i+1 < H){
                    ll tt = abs(A[i+1][j] - B[i+1][j]);
                    if(dp[i][j][k]){
                        dp[i+1][j][k+tt] = true;
                        dp[i+1][j][k-tt] = true;
                    }
                }
                if(j+1 < W){
                    ll tt = abs(A[i][j+1] - B[i][j+1]);
                    if(dp[i][j][k]){
                        dp[i][j+1][k+tt] = true;
                        dp[i][j+1][k-tt] = true;
                    }
                }
            }
        }
    }
    ll ans = INF;
    rep(k,0,80*80*2+2){
        if(dp[H-1][W-1][k]){
            ans = min(ans, abs(k - thre));
        }
    }
    print(ans);


    

}
