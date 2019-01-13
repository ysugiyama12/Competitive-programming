#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H ,W, K;
    cin >> H >> W >> K;
    ll num[10][10] = {};
    rep(i,0,(1 << (W-1))){
        if((i & i << 1)) continue;
        int arr[10] = {};
        rep(j,0,W-1){
            if((i >> j) & 1){
                arr[j] = 1;
            }else{
                arr[j] = 0;
            }
        }
        rep(j,0,W-1){
            if(arr[j] == 1){
                num[j][j+1]++;
                num[j+1][j]++;
            }
            if(j != W-2){
                if(arr[j] == 0 && arr[j+1] == 0){
                    num[j+1][j+1]++;
                }
            }else{
                if(arr[j] == 0){
                    num[j+1][j+1]++;
                }
            }
            if(j == 0){
                if(arr[j] == 0){
                    num[0][0]++;
                }
            }
        }
    }
    // printa2(num, W, W);
    ll dp[110][10] = {};
    dp[0][0] = 1;
    rep(i,0,H){
        rep(k,0,W){
            rep(j,0,W){
                dp[i+1][k] += dp[i][j] * num[j][k];
                dp[i+1][k] %= MOD;
            }
        }
    }
    if(W == 1){
        print(1);
    }else{
        print(dp[H][K-1]);
    }
}
