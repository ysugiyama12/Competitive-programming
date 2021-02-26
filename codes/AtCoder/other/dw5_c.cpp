#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)

ll dp[1000010][4] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    string S;
    ll k[110];
    cin >> N >> S >> Q;
    rep(i,0,Q) cin >> k[i];
    ll cnt_M[1000010] = {};
    rep(i,0,N){
        if(S[i] == 'D'){
            dp[i+1][0] += dp[i][0] + 1;
            dp[i+1][1] += dp[i][1];
            dp[i+1][2] += dp[i][2];
        }else if(S[i] == 'M'){
            cnt_M[i+1] = 1;
            dp[i+1][1] += dp[i][0] + dp[i][1];
            dp[i+1][0] = dp[i][0];
            dp[i+1][2] = dp[i][2];
        }else if(S[i] == 'C'){ 
            dp[i+1][2] += dp[i][1];
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
        }else{
            dp[i+1][2] = dp[i][2];
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];

        }
    }
    rep(i,0,N+1) cnt_M[i+1] += cnt_M[i];
    rep(q,0,Q){
        ll ans = 0;
        rep(i,0,N){
            if(S[i] == 'C'){
                if(i < k[q]){
                    ans += dp[i+1][1];
                }else{
                    ans += dp[i+1][1] - dp[i+1-k[q]][1] - dp[i+1-k[q]][0] * (cnt_M[i+1] - cnt_M[i+1-k[q]]);
                }
            }
        }
        print(ans);
    }
}