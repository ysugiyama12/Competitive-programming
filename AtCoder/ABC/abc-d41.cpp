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

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll x[210], y[210];
    vector<ll> tree[20];
    rep(i,0,M) cin >> x[i] >> y[i];
    rep(i,0,M){
        x[i]--; y[i]--;
        tree[x[i]].push_back(y[i]);
    }

    ll dp[1LL<<17] = {};
    dp[0] = 1;
    rep(bit,0,(1LL<<N)){
        rep(i,0,N){
            if((bit>>i) & 1) continue;
            bool ok = true;
            for(auto &e: tree[i]){
                if((bit>>e) & 1) ok = false;
            }
            if(ok){
                dp[bit | (1<<i)] += dp[bit];
            }
        }

    }
    print(dp[(1LL<<N) - 1]);
}
