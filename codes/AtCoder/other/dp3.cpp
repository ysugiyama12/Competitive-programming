#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;
int dp[110][10010];
const int MOD = 1000000009;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    int a[110];
    int A;
    cin >> N >> A;
    rep(i,0,N){
        cin >> a[i];
    }
    rep(i,1,A+1){
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    rep(i,0,N){
        rep(j,0,A+1){
            if(j >= a[i]){
                dp[i+1][j] = (dp[i][j - a[i]] + dp[i][j])%MOD;
            }else{
                dp[i+1][j] = (dp[i][j])%MOD;
            }
        }
    }
    print(dp[N][A]);
}
