#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
map<ll,ll> dp[100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    ll a[100010];
    cin >> N >> K;
    rep(i,0,N) cin >> a[i];
    dp[0][0] = 1;
    sort(a, a+N);
    ll limit = a[0];
    rep(i,0,N){
        rep(j,0,limit+1){
            dp[i+1][j] += dp[i][j] % MOD;
            dp[i+1][j] %= MOD;
            dp[i+1][j^a[i]] += dp[i][j] % MOD;
            dp[i+1][j^a[i]] %= MOD;
        }
        limit |= a[i+1];
    }
    print(dp[N][K]);
}
