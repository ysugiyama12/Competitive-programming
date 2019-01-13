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
const int MOD = 1e9 + 7;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();
    ll dp[100010][4] = {};
    for(int i = N; i >= 0; i--){
        for(int j = 3; j >= 0; j--){
            if(i == N){
                dp[i][j] = (j == 3 ? 1 : 0);
            }else{
                dp[i][j] = (S[i] == '?' ? 3 : 1) * dp[i+1][j];
                if(j < 3 && (S[i] == '?' || "ABC"[j] == S[i])){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
            dp[i][j] %= MOD;
        }
    }
    print(dp[0][0]);
}
