/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
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
    ll N,M;
    cin >> N >> M;
    ll dp[100010] = {};
    dp[0] = 1;
    rep(i,0,N){
        if(i != 0){
            dp[i+1] = dp[i] + dp[i-1];
            dp[i+1] %= MOD;
        }else{
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
        }
    }
    ll dp2[100010] = {};
    dp2[0] = 1;
    rep(i,0,M){
        if(i != 0){
            dp2[i+1] = dp2[i] + dp2[i-1];
            dp2[i+1] %= MOD;
        }else{
            dp2[i+1] = dp2[i];
            dp2[i+1] %= MOD;
        }   
    }
    ll ans = 2 * dp2[M] % MOD + (dp[N] - 1 + MOD) * 2 % MOD;
    ans %= MOD;
    print(ans);

    

}