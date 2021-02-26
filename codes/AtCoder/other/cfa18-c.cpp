#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll dp[55][4100][3] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll A[55];
    rep(i,0,N) cin >> A[i];
    ll cnt[55] = {};
    rep(i,0,N){
        ll n = A[i];
        while(n > 0){
            cnt[i]++;
            n /= 2;
        }
    }
    dp[0][0][0] = 1;
    rep(i,0,N){
        rep(j,0,4000){
            rep(k,0,cnt[i]){
                dp[i+1][j+k][0] += dp[i][j][0];
                dp[i+1][j+k][0] %= MOD;
            }
            dp[i+1][j+cnt[i]][1] += dp[i][j][0];
            dp[i+1][j+cnt[i]][1] %= MOD;
            rep(k,0,cnt[i]+1){
                dp[i+1][j+k][1] += dp[i][j][1];
                dp[i+1][j+k][1] %= MOD;
            }
        }
    }
    ll ans = 0;
    ll kk = min(4000LL, K);
    ans += dp[N][kk][0] % MOD;
    rep(i,0,kk+1){
        ans += dp[N][i][1] % MOD;
        ans %= MOD;
    }
    print(ans);
}
