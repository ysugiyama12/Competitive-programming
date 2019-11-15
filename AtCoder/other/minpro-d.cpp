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
ll dp[200010][5] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll L;
    cin >> L;
    ll A[200010];
    rep(i,0,L) cin >> A[i];
    rep(i,0,L+1){
        rep(j,0,5){
            if(i == 0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INF;
            }
        }
    }

    rep(i,0,L){
        rep(j,0,5){
            rep(k,0,j+1){
                ll val = 0;
                if(j == 0 || j == 4){
                    val = A[i];
                }else if(j == 1 || j == 3){
                    val = A[i] % 2;
                    if(A[i] == 0) val += 2;
                }else{
                    val = (A[i] + 1) % 2;
                }
                dp[i+1][j] = min(dp[i+1][j], dp[i][k] + val);
            }
        }
    }
    ll ans = INF;
    rep(i,0,5) ans = min(ans, dp[L][i]);
    print(ans);
    

}