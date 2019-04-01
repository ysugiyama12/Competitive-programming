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
ll dp[5010][5010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,A,B;
    cin >> N >> A >> B;
    ll P[5010];
    rep(i,0,N) cin >> P[i];
    rep(i,0,N){
        rep(j,0,N){
            if(i == j){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INF;
            }
        }
    }
    rep(lv,0,N){
        rep(rv,0,N){
            ll cnt = rv - lv + 1;
            

        }
    }
    
    print(dp[0][N-1]);

    
}