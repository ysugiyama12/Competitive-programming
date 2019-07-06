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
ll dp[16][1LL<<16];
ll s[200], t[200], d[200];
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll dist[20][20] = {};
    rep(i,0,N){
        rep(j,0,N){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    rep(i,0,M){
        cin >> s[i] >> t[i] >> d[i];
        dist[s[i]][t[i]] = d[i];
    }
    rep(i,0,N){
        rep(j,0,(1LL<<N)){
            dp[i][j] = INF;
        }
    }
    dp[0][1] = 0; //dp[i][j]: 今iにいて訪れたことのある頂点集合がjの時の最短距離
    rep(bit,0,(1LL<<N)){
        rep(i,0,N){
            if(dp[i][bit] == INF) continue;
            rep(j,0,N){
                if((bit>>j) & 1) continue;
                dp[j][bit | (1LL<<j)] = min(dp[j][bit | (1LL<<j)], dp[i][bit] + dist[i][j]);
            }
        }
    }
    ll ans = INF;
    rep(i,0,N){
        ans = min(ans, dp[i][(1LL<<N)-1] + dist[i][0]);
    }
    if(ans == INF){
        print(-1);
    }else{
        print(ans);
    }
 
     
}