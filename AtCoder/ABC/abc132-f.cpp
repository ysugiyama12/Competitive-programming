#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int M = 1e9+7;

long long v[2010][2010] = {};

long long combination(long long n, long long k) {
  if(v[n][k] != 0) return v[n][k];
  if (n == k || k == 0)
    return 1;
  else {
      v[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
      return v[n][k];
  }
}

int main(){
  int N,K; cin >>N >>K;

  long long int ans;

  for(int i=1;i<=K;i++){
    if(N-K+1<i) ans = 0;
    else {
      ans = (combination(N-K+1,i)%M * combination(K-1,i-1)%M) % M;
      ans %= M;
    }
    cout << ans << endl;
  }
  return 0;
}
