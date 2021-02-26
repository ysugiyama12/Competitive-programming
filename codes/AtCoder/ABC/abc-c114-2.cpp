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
string N;
ll dp[50][2][2][2][2][2][2];
ll rec(ll k=0, bool tight=true, bool c3=false, bool c5=false, bool c7=false, bool other=true, bool zero=true){
    if(k == N.size()){
        return (c3 && c5 && c7 && other);
    }
    ll x = N[k] - '0';
    ll r = (tight ? x : 9);
    if(dp[k][tight][c3][c5][c7][other][zero] != -1) return dp[k][tight][c3][c5][c7][other][zero];
    ll res = 0;
    rep(i,0,r+1){
        res += rec(k+1, tight && i == r, c3||i==3, c5||i==5, c7||i==7, (zero&&i==0)||(other && (i == 3 || i == 5 || i == 7)), zero&&i==0);
    }
    dp[k][tight][c3][c5][c7][other][zero] = res;
    return res;


}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    print(rec());
}
