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
ll N;
ll a[25][25];
ll dp[25][1LL<<22] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N){
        rep(j,0,N){
            cin >> a[i][j];
        }
    }
    dp[0][0] = 1;
    rep(bit,0,(1LL<<N)){
        ll i = __builtin_popcount(bit);
        // if(__builtin_popcount(bit) != i) continue; //ペアリングが一致していない時
        rep(j,0,N){
            if(a[i][j] == 1 && (((bit << j) & 1) == 0)){
                dp[i+1][bit | (1 << j)] += dp[i][bit] % MOD;
                dp[i+1][bit | (1 << j)] %= MOD;
            }
        }
    }
    print(dp[N][(1LL<<N) - 1]);

}
