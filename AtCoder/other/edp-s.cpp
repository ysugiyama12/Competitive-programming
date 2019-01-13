#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
string K;
ll D;
ll dp[10010][2][110];
ll rec(ll k = 0, ll tight = 1, ll sum = 0){
    if(k == K.size()){
        return (sum == 0);
    }
    ll x = K[k] - '0';
    ll r = tight ? x : 9;
    ll &res = dp[k][tight][sum];
    if(~res) return res;
    res = 0;
    rep(i,0,r+1){
        res += rec(k+1, tight && (i == r), (sum + i) % D) % MOD;
        res %= MOD;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> K;
    cin >> D;
    memset(dp, -1, sizeof(dp));
    ll ans = rec();
    print((ans - 1 + MOD) % MOD);

}
