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
string A;
ll K;
ll dp[20][2][1L<<10];
ll rec(ll k=0, ll tight=true, ll use=0){
    if(k == A.size()){

    }
    ll x = A[k] - '0';
    ll r = (tight ? x : 9);
    ll &res = dp[k][tight][use];
    if(~res) return res;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> K;
    memset(dp, -1, sizeof(dp));
    print(rec());
    
    
}
