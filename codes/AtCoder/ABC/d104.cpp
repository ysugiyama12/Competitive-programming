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
    string S;
    cin >> S;
    ll N = S.size();
    ll dp[100010][4] = {};
    dp[0][0] = 1;
    rep(i,0,N){
        rep(j,0,4){
            if(S[i] == '?'){
                dp[i+1][j] += 3 * dp[i][j];
                if(j != 0) dp[i+1][j] += dp[i][j-1];
            }else{
                dp[i+1][j] += dp[i][j];
                if(j != 0 && S[i] == "ABC"[j-1]) dp[i+1][j] += dp[i][j-1];
            }
            dp[i+1][j] %= MOD;
        }
    }
    print(dp[N][3]);
}
