#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)
ll dp[10][200010] = {};
int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    string A;
    cin >> A;
    ll N = A.size();
    rep(bit,1,pow(27,3)){
        if(bit % 27 == 0) continue;
        char s[3];
        ll idx = 0;
        ll n = bit;
        while(n > 0){
            s[idx] = 'a' + (n % 27 - 1);
            // print(s[idx]);
            n /= 27;
            idx++;
        }
        string ss = "";
        rep(i,0,idx) ss += s[i];
        ll ns = ss.size();
        rep(i,0,ns){
            rep(j,0,N){
                if(ss[i] == A[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        if(dp[ns][N] != ns){
            print(ss);
            return 0;
        }
    }
}
