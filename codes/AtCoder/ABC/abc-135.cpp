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
ll power(ll x, ll n){
    if(n == 0) return 1LL;
    ll res = power(x * x % 13, n/2);
    if(n % 2 == 1) res = res * x % 13;
    return res;
}

ll dp[100010][15] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    dp[0][0] = 1;
    ll val[100010];
    rep(i,0,100001) val[i] = power(10, i);
    reverse(S.begin(), S.end());
    rep(i,0,N){
        rep(j,0,13){
            if(S[i] == '?'){
                rep(k,0,10){
                    ll amari = k * val[i] % 13;
                    dp[i+1][(j+amari) % 13] += dp[i][j] % MOD;
                    dp[i+1][(j+amari) % 13] %= MOD;
                }
            }else{
                ll v = S[i] - '0';
                ll amari = v * val[i] % 13;
                dp[i+1][(j+amari) % 13] += dp[i][j] % MOD;
                dp[i+1][(j+amari) % 13] %= MOD;
            }

        }
    }
    print(dp[N][5]);
    
}