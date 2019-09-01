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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll c[30010];
    rep(i,0,N) cin >> c[i];
    ll dp[30010];
    fill(dp, dp+N, INF);
    rep(i,0,N){
        ll pos = lower_bound(dp, dp+N, c[i]) - dp;
        dp[pos] = c[i];
    }
    rrep(i,N-1,0){
        if(dp[i] != INF){
            print(N - (i+1));
            return 0;
        }
    }
    
}