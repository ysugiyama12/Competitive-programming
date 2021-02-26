#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll dp[5010][5010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    ll a[5010];
    cin >> N >> K;
    rep(i,0,N) cin >> a[i];
    sort(a, a+N);
    // ll ans = 0;
    // if(N > 400 || K > 400) return 0;
    ll rv = N, lv = -1;
    while(rv - lv > 1){
        ll t = (rv+lv)/2;
        ll tmp = a[t];
        a[t] = 0;
        rep(i,0,N+1){
            rep(j,0,K+1){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        rep(i,0,N){
            rep(j,0,K+1){
                dp[i+1][j] |= dp[i][j];
                if(j - a[i] >= 0){
                    dp[i+1][j] |= dp[i][j - a[i]];
                }
            }
        }
        bool ok = false;
        if(K - tmp < 0){
            rv = t;
            continue;
        }
        rep(i,K-tmp,K){
            if(dp[N][i] == 1) ok = true;
        }
        // if(!ok) ans++;
        a[t] = tmp;
        if(!ok){
            lv = t;
        }else{
            rv = t;
        }
    }
    print(lv+1);
    // rep(t,0,N){
    //     ll tmp = a[t];
    //     a[t] = 0;
    //     rep(i,0,N+1){
    //         rep(j,0,K+1){
    //             dp[i][j] = 0;
    //         }
    //     }
    //     dp[0][0] = 1;
    //     rep(i,0,N){
    //         rep(j,0,K+1){
    //             dp[i+1][j] |= dp[i][j];
    //             if(j - a[i] >= 0){
    //                 dp[i+1][j] |= dp[i][j - a[i]];
    //             }
    //         }
    //     }
    //     bool ok = false;
    //     if(K - tmp < 0) continue;
    //     rep(i,K-tmp,K){
    //         if(dp[N][i] == 1) ok = true;
    //     }
    //     if(!ok) ans++;
    //     a[t] = tmp;
    // }
    // print(ans);


}
