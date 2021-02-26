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
ll D;
string N;
ll dp[10010][2][110];

ll rec(ll k, bool tight, ll sum){
    if(k == N.size()){
        return (sum == 0);
    }
    ll x = N[k] - '0';
    ll r = (tight ? x : 9);
    if(dp[k][tight][sum] != -1) return dp[k][tight][sum];
    ll res = 0;
    rep(i,0,r+1){
        res += rec(k+1, tight && i == r, (sum + i) % D);
        res %= MOD;

    }
    dp[k][tight][sum] = res;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> D;
    cin >> N;
    memset(dp, -1, sizeof(dp));
    print(rec(0, true, 0)-1);

}
