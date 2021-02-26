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
ll dp[300010][5] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    while(Q--){
        ll N;
        cin >> N;
        ll a[300010], b[300010];
        rep(i,0,N) cin >> a[i] >> b[i];
        rep(i,0,N+1){
            rep(j,0,3){
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        rep(i,0,N){
            rep(j,0,3){
                rep(k,0,3){
                    if(i > 0){
                        if(a[i-1] + k == a[i] + j) continue;
                    }
                    dp[i+1][j] = min(dp[i+1][j],dp[i][k] + b[i] * j);
                }
            }
        }
        ll ans = INF;
        rep(j,0,3){
            ans = min(ans, dp[N][j]);
        }
        cout << ans << "\n";

    }

    
}