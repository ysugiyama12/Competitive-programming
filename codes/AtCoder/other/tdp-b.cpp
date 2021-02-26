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
    ll A,B;
    ll a[1010], b[1010];
    cin >> A >> B;
    rep(i,0,A){
        cin >> a[i];
    }
    rep(i,0,B){
        cin >> b[i];
    }
    ll dp[1010][1010] = {};
    dp[0][0] = 0;
    ll val = (A+B) % 2;
    rep(i,0,A+1){
        rep(j,0,B+1){
            if((i+j) % 2 == val){ //先手が取る
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    dp[0][j] = dp[0][j-1] + b[B-j];
                }else if(j == 0){
                    dp[i][0] = dp[i-1][0] + a[A-i];
                }else{
                    dp[i][j] = max(dp[i-1][j] + a[A-i], dp[i][j-1] + b[B-j]);
                }
            }else{
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    dp[0][j] = dp[0][j-1];
                }else if(j == 0){
                    dp[i][0] = dp[i-1][0];
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    print(dp[A][B]);


}
