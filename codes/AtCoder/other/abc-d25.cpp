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
ll dp[1LL<<25] = {};
ll A[5][5];

bool judge(ll bit, ll i) {
    return false;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A[5][5];
    rep(i,0,5){
        rep(j,0,5){
            cin >> A[i][j];
        }
    }
    dp[0] = 1;
    rep(bit,0,(1LL<<25)){
        ll cnt = __builtin_popcount(bit);
        rep(i,0,25){
            if((bit>>i) & 1) continue;
            if(judge(bit, i)){
                dp[bit | (1LL<<i)] += dp[bit];
                dp[bit | (1LL<<i)] %= MOD;
            }
        }
    }
    

    
}