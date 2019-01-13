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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M;
    ll MOD = 1000000007;
    int f[100010];
    cin >> N >> M;
    rep(i,0,N) cin >> f[i];
    bool taste[100010];
    int left = -1;
    int right = 0;

    ll sum[100010] = {};
    sum[0] = 0;
    sum[1] = 1;
    sum[2] = 2;

    ll dp[100010];
    dp[0] = 1;
    dp[1] = 1;
    taste[f[0]] = true;

    rep(i,2,N+1){
        right = i-1;
        if(taste[f[right]]){
            if(left == -1){
                left++;
            }
            while(1){
                if(f[right-1] == f[right]){
                    left = right-1;
                    break;
                }
                if(f[left] == f[right]) break;
                taste[f[left]] = false;
                left++;
            }

        }else{
            taste[f[right]] = true;
        }
        if(left == -1){
            dp[i] = sum[i]%MOD;
        }else{
            dp[i] = (sum[right+1] - sum[left+1])%MOD;
        }
        sum[i+1] = (sum[i] + dp[i])%MOD;
    }
    // printa(dp,N+1);
    print(dp[N]%MOD);



}
