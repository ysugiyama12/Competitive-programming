#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int N;
double p[3333];
double dp[3333][3333]; // dp[i][j]: 表i枚、裏j枚が出る確率
 
signed main() {
  // 入力
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
 
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        if(i+j > N) continue;
      // おもて
      dp[i+1][j] += dp[i][j] * p[i+j];
      // うら
      dp[i][j+1] += dp[i][j] * (1 - p[i+j]);
    }
  }
 
  double ans = 0;
  for (int i = N/2+1; i <= N; i++) {
    int j = N - i;
    ans += dp[i][j];
  }
 
  printf("%.10f\n", ans);
 
  return 0;
}