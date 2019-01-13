#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
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
    int N;
    int p[110];
    cin >> N;
    rep(i,0,N){
        cin >> p[i];
    }
    int dp[10010] = {};
    dp[0] = 1;
    rep(i,0,N){
        for(int j = 10010; j >= 0; j--){
            if(dp[j] == 1){
                dp[j + p[i]] = 1;
            }
        }
    }
    int ans = 0;
    rep(i,0,10010){
        if(dp[i] == 1){
            ans++;
        }
    }
    print(ans);

}
