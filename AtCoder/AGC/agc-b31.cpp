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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll C[200010];
    cin >> N;
    rep(i,0,N) cin >> C[i];
    ll ans = 0;
    ll dp[200010] = {};
    dp[0] = 1;
    map<ll, ll> mp;
    rep(i,0,200010){
        mp[i] = -1;
    }
    rep(i,0,N){
        if(mp[C[i]] == -1){
            dp[i+1] = dp[i];
            mp[C[i]] = i;
        }else{
            if(mp[C[i]] + 1 == i){
                mp[C[i]] = i;
                dp[i+1] = dp[i];
                continue;
            }
            // print2(mp[C[i]], i);
            dp[i+1] += (dp[i] + dp[mp[C[i]]+1]) % MOD;
            dp[i+1] %= MOD;
            mp[C[i]] = i;
            // print(dp[i+1]);
        }
    }
    print(dp[N]);


}