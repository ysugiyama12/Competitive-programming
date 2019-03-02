#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    ll b[200010];
    cin >> N >> K;
    rep(i,0,N) cin >> b[i];
    ll dp[200010] = {};
    ll max_val[200010] = {};
    rep(i,0,N){
        if(i - K + 1 >= 0){
            dp[i+1] = max(dp[i] + b[i], max_val[i-K+1]);
        }else{
            dp[i+1] = dp[i] + b[i];
        }
        max_val[i+1] = max(max_val[i], dp[i+1]);

    }
    print(dp[N]);
  

}
