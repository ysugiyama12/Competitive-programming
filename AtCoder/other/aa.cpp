#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
bool used[101010];
priority_queue<int, vector<int>, greater<int>> dup;
 
signed main() {
 
  int N, K;
  cin >> N >> K;
 
  vector<pair<int, int>> sushi;
  for (int i = 0; i < N; ++i) {
    int t, d;
    cin >> t >> d;
    sushi.emplace_back(make_pair(d, t));
  }
 
  sort(sushi.rbegin(), sushi.rend());
 
  int var = K;
  long long delic = 0;
  for (int i = 0; i < K; ++i) {
    int d, t;
    tie(d, t) = sushi[i];
    if (used[t]) {
      dup.push(d);
      --var;
    }
    used[t] = true;
    delic += d;
  }
 
  long long res = delic + var * var;
  for (int i = K; i < N; ++i) {
    int d, t;
    tie(d, t) = sushi[i];
    if (used[t]) continue;
    var++;
    used[t] = true;
    if(dup.empty()) continue;
    delic -= dup.top(); dup.pop();
    delic += d;
    res = max(res, delic + var * var);
  }
 
  cout << res << endl;
 
}