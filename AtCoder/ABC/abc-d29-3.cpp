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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll dp[12][2][12] = {};
    dp[0][0][0] = 1;
    string sN = to_string(N);
    ll keta = sN.size();
    rep(i,0,keta){
        ll D = sN[i] - '0';
        rep(sum,0,keta+1){
            rep(mask,0,2){
                ll end = (mask ? 10 : D+1);
                rep(d,0,end){
                    if(d == 1){
                        dp[i+1][mask || d < D][sum+1] += dp[i][mask][sum];
                    }else{
                        dp[i+1][mask || d < D][sum] += dp[i][mask][sum];
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i,1,keta+1){
        ans += i * (dp[keta][0][i] + dp[keta][1][i]);
    }
    print(ans);
}