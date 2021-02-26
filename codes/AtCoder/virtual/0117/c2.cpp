#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll dp[5010][5010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X;
    cin >> N >> X;
    ll T[5010];
    rep(i,0,N){
        cin >> T[i];
    }
    dp[1][1] = X;
    rep(i,1,N+1){
        rep(j,1,N+1){
            rep(k,1,i){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[k][j] + min(X, T[i-1] - T[k]));
            }
        }
    }
    rep(k,1,N+1){
        ll val = 0;
        rep(i,1,N+1){
            val = max(val, dp[i][k]);
        }
        print(val);
    }
}
