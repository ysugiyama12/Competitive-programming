/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

void solve(){
    ll V,E;
    cin >> V >> E;
    vector<vll> dist(V+1, vll(V+1, -1));

    rep(i,0,E){
        ll s,t,d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    vector<vll> dp(V+1, vll(1LL<<V, INF));

    dp[0][1] = 0;

    rep(bit,0,1LL<<V){
        rep(i,0,V){
            if(dp[i][bit] == INF) continue;
            rep(j,0,V){
                if(bit & (1LL<<j)) continue;
                if(dist[i][j] == -1) continue;
                dp[j][bit | (1LL<<j)] = min(dp[j][bit | (1LL<<j)], dp[i][bit] + dist[i][j]);
            }
        }
    }

    ll ans = INF;
    rep(i,0,V){
        if(dist[i][0] == -1) continue;
        ans = min(ans, dp[i][(1LL<<V)-1] + dist[i][0]);
    }

    if(ans == INF){
        print(-1);
    }else{
        print(ans);
    }

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}