#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    ll A[1010] = {};
    cin >> T;
    rep(i,0,T) cin >> A[i];
    ll dp[1010][1010] = {};
    dp[0][0] = 1;
    rep(i,0,1000){
        rep(j,0,1000){
            // print2(i,j);
            if(j % 2 == 1) continue;
            if(dp[i][j] == 0) continue;
            if(i >= T) continue;
            rep(k,0,A[i]+1){
                if(k+j/2 > 1000) continue;
                dp[i+1][k + j/2] += dp[i][j];
                dp[i+1][k + j/2] %= MOD;
            }

        }
    }
    ll ans = 0; 
    rep(i,0,1000){
        ans += dp[i+1][1];
        ans %= MOD;
    }
    print(ans);
}
