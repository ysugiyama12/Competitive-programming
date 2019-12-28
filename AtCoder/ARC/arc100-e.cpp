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
ll A[(1LL<<18) + 10];
lpair dp[(1LL<<18) + 1][19];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll M = (1LL<<N);
    rep(i,0,M) cin >> A[i];
    rep(i,0,M){
        dp[i][0] = {A[i], 0};
    }
    rep(j,0,N){
        rep(i,0,M){
            if(i & (1LL<<j)){
                ll arr[4];
                arr[0] = dp[i][j].first;
                arr[1] = dp[i][j].second;
                arr[2] = dp[i & ~(1LL<<j)][j].first;
                arr[3] = dp[i & ~(1LL<<j)][j].second;
                sort(arr, arr+4);
                // printa(arr,4);
                dp[i][j+1] = {arr[2], arr[3]};
            }else{
                dp[i][j+1] = dp[i][j];
            }
        }
    }
    ll ans = 0;
    rep(i,1,M){
        ans = max(ans, dp[i][N].first + dp[i][N].second);
        print(ans);
    }
}