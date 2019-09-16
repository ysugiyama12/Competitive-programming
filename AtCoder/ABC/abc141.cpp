/*** author: yuji9511 ***/
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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll dp[5010][5010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    rrep(i,N-1,0){
        rrep(j,N-1,0){
            if(S[i] == S[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
            }else{
                dp[i][j] = 0;
            }
        }
    }
    ll ans = 0;
    rep(i,0,N){
        rep(j,0,N){
            if(abs(j - i) >= dp[i][j]) ans = max(ans, dp[i][j]);
        }
    }
    print(ans);
    
}