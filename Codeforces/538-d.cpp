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
ll dp[5010][5010] = {};// N個目まで見たときに全てC色になっている場合の数

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll c[5010];
    rep(i,0,N) cin >> c[i];
    ll ans = INF;
    rep(col,1,5001){
        vector<ll> tt;
        ll v = 0;
        if(c[0] != col) v = c[0];
        rep(i,1,N){
            if(c[i] == col){
                if(v > 0){
                    tt.push_back(v);
                    v = 0;
                }
            }else if(c[i-1] == col){
                v = c[i];
            }else if(c[i-1] != c[i]){
                tt.push_back(v);
                v = c[i];
            }else{
                
            }
        }
        if(v > 0) tt.push_back(v);
        map<ll,ll> mp;
        ll n = tt.size();
        ll cnt = 1;
        mp[tt[0]]++;
        rep(i,1,n){
            if(cc)


        }
        // rep(i,0,tt.size()){
        //     mp[tt[i]]++;
        // }
        // ll cnt = mp.size();
        //         rep(i,0,tt.size()-1){
        //     if()
        // }
        ans = min(ans, cnt);

        // ll cnt = tt.size();

        // printa(tt,tt.size());
    }
    print(ans);
    // memset(dp, -1, sizeof(dp));
    // rep(i,1,5001){
    //     if(c[0] == i){
    //         dp[0][i] = 0;
    //     }else{
    //         dp[0][i] = 1;
    //     }
    // }
    // ll is_use[5010] = {};
    // map<ll,ll> mp;
    // rep(i,0,N){
    //     if(mp[c[i]] != 0){
    //         is_use[i] = 1;
    //     }
    //     mp[c[i]]++;
    // }
    // rep(j,1,5001){
    //     rep(i,1,N){
    //         if(c[i-1] == c[i] || c[i] == j || is_use[i] == 1){
    //             dp[i][j] = dp[i-1][j];
    //         }else{
    //             dp[i][j] = dp[i-1][j] + 1;
    //         }

    //     }
    // }
    // rep(i,1,N){
    //     rep(j,1,5001){
    //         map<ll,ll> mp;
    //         if(c[i-1] == c[i] || c[i] == j){
    //             dp[i][j] = dp[i-1][j];
    //         }else{
    //             dp[i][j] = dp[i-1][j] + 1;
    //         }
    //     }
    // }
    // ll ans = INF;
    // rep(i,1,5001){
    //     ans = min(ans, dp[N-1][i]);
    // }
    // print(ans);

    

}
