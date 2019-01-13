#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll a[310];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    rep(i,1,T+1){
        cin >> a[i];
    }
    ll ans = 0;
    ll dp[310][310] = {};
    rep(i,0,T+2){
        dp[i][0] = 1;
    }
    rep(t,1,T+2){
        rep(n,0,310){
            rep(k,0,n*2+1){
                if(a[t] >= k){
                    dp[t][n] += dp[t-1][n*2 - k] % MOD;
                }
            }
        }
    }
    rep(i,1,T+2){
        ans += dp[i][1] % MOD;
    }
    print(ans);
}
