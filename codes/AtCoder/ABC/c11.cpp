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
    int N;
    int g1,g2,g3;
    cin >> N >> g1 >> g2 >> g3;
    int dp[301];
    rep(i,0,N+1){
        dp[i] = INF;
    }
    dp[N] = 0;
    if(N == g1 || N == g2 || N == g3){
        print("NO");
        return 0;
    }
    for(int i = N; i >= 0; i--){
        if(i == g1 || i == g2 || i == g3) continue;
        rep(j,1,4){
            if(i - j >= 0){
                dp[i - j] = min(dp[i - j], dp[i] + 1);
            }
        }
    }
    if(dp[0] <= 100){
        print("YES");
    }else{
        print("NO");
    }


}
