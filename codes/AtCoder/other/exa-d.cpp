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
ll dp[210][100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X;
    cin >> N >> X;
    ll S[210];
    rep(i,0,N) cin >> S[i];
    dp[0][X] = 1;
    sort(S, S+N, greater<ll>());
    rep(i,0,N){
        rep(x,0,X+1){
            (dp[i+1][x % S[i]] += dp[i][x]) %= MOD;
            (dp[i+1][x] += dp[i][x] * (N-i-1)) %= MOD;
        }
    }
    ll ans = 0;
    // rep(x,0,X+1) print(x, dp[1][x]);
    rep(x,0,X+1){
        ans += dp[N][x] * x;
        ans %= MOD;
    }
    print(ans);


    

}