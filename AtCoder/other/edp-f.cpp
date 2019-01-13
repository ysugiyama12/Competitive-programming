#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll dp[3010][3010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    ll ns = s.size();
    ll nt = t.size();
    rep(i,0,ns){
        if(s[i] == t[0]){
            dp[i][0] = 1;
        }else{
            dp[i][0] = 0;
        }
        if(i != 0){
            dp[i][0] = max(dp[i-1][0], dp[i][0]);
        }
    }
    rep(j,0,nt){
        if(s[0] == t[j]){
            dp[0][j] = 1;
        }else{
            dp[0][j] = 0;
        }
        if(j != 0){
            dp[0][j] = max(dp[0][j], dp[0][j-1]);
        }
    }
    rep(i,1,ns){
        rep(j,1,nt){
            if(s[i] == t[j]){
                // ll max_val = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
        }
    }
    // print(dp[ns-1][nt-1]);
    // rep(i,0,ns){
    //     rep(j,0,nt){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // ll idx = dp[ns-1][nt-1];
    // ll px = ns-1, py = nt-1;
    // while(idx > 0){
    //     while()

    // }
    // cout << endl;
    string ans = "";
    ll px = ns-1, py = nt-1;
    while(px >= 0 && py >= 0){
        if(s[px] == t[py]){
            ans += s[px];
            px--;
            py--;
        }else{
            if(px == 0){
                py--;
            }else if(py == 0){
                px--;
            }else if(dp[px-1][py] > dp[px][py-1]){
                px--;
            }else{
                py--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    print(ans);


}
