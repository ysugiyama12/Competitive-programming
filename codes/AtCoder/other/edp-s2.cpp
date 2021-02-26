#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
ll dp[10010][110][2] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string K;
    ll D;
    cin >> K >> D;
    dp[0][0][0] = 1;
    ll keta = K.size();
    rep(i,0,keta){
        ll v = K[i] - '0';
        rep(j,0,D){
            rep(mask,0,2){
                ll end = (mask ? 10 : v+1);
                rep(d,0,end){
                    dp[i+1][(j + d) % D][mask || d < v] += dp[i][j][mask] % MOD;
                    dp[i+1][(j + d) % D][mask || d < v] %= MOD;
                }
            }
        }
    }
    ll ans = (dp[keta][0][0] + dp[keta][0][1] - 1 + MOD) % MOD;
    print(ans);


    
}