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
ll dp[1010][2020] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll n = S.size();
    ll nplus = 0, nminus = 0;
    rep(i,0,n){
        if(S[i] == '+') nplus++;
        if(S[i] == '-') nminus++;
    }
    vector<ll> A;
    rep(i,0,n){
        if(S[i] == 'M'){
            A.push_back(nplus - nminus);
        }else if(S[i] == '+'){
            nplus--;
        }else{
            nminus--;
        }
    }
    sort(A.begin(), A.end());
    ll na = A.size();
    ll ans = 0;
    rep(i,0,na){
        if(i < na/2){
            ans -= A[i];
        }else{
            ans += A[i];
        }
    }
    print(ans);
    // if(n > 1000) return 0;
    // ll offset = 1010;
    // rep(i,0,1010){
    //     rep(j,0,2020){
    //         dp[i][j] = -INF;
    //     }
    // }
    // dp[0][offset] = 0;
    // rep(i,0,n){
    //     rep(j,0,2020){
    //         ll x = j - offset;
    //         if(S[i] == 'M'){
    //             dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
    //             dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]);
    //         }else if(S[i] == '+'){
    //             dp[i+1][j] = max(dp[i+1][j], dp[i][j] + x);
    //         }else{
    //             dp[i+1][j] = max(dp[i+1][j], dp[i][j] - x);
    //         }
    //     }
    // }
    // print(dp[n][offset]);


}
