#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll H,W;
char S[110][110];
ll dp[110][110];
ll rec(ll h, ll w){
    ll &res = dp[h][w];
    if(~res) return res;
    if(S[h][w] == '#' || h >= H || w >= W) return res = 1;
    if(rec(h+1,w) == 0) return res = 1;
    if(rec(h+1,w+1) == 0) return res = 1;
    if(rec(h,w+1) == 0) return res = 1;
    return res = 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    rep(i,0,H){
        rep(j,0,W){
            cin >> S[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    ll ans = rec(0,0);
    if(ans){
        print("First");
    }else{
        print("Second");
    }
    
}
