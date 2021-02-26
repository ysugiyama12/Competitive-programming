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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll f[100010];
    cin >> N >> M;
    rep(i,1,N+1){
        cin >> f[i];
    }
    f[0] = 100009;
    ll dp[100010] = {}, cnt[100010] = {}, dp_sum[100010] = {};
    ll lv = 0, rv = -1;
    dp[0] = 1;
    dp_sum[1] = dp[0];
    rep(i,1,N+1){
        rv++;
        cnt[f[rv+1]]++;
        while(cnt[f[rv+1]] == 2){
            cnt[f[lv+1]]--;
            lv++;
        }
        dp[i] = (dp_sum[rv+1] - dp_sum[lv] + MOD) % MOD;
        dp_sum[i+1] = (dp_sum[i] + dp[i]) % MOD;
    }
    print(dp[N]);

}
