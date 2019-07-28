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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,X,Y;
    cin >> N >> M >> X >> Y;
    ll A[15], B[21];
    rep(i,0,N) cin >> A[i];
    rep(i,0,M) cin >> B[i];
    ll dp[21][1LL<<13] = {};
    rep(i,0,M+1){
        rep(bit,0,(1LL<<N)){
            dp[i][bit] = INF;
        }
    }
    dp[0][0] = 0;
    ll num[1LL<<13] = {};
    rep(bit,0,(1LL<<N)){
        ll t = 0;
        rep(i,0,N){
            if((bit>>i) & 1){
                t += A[i];
            }
        }
        num[bit] = t;
    }
    rep(i,0,M){
        rep(prev,0,(1LL<<N)){
            if(dp[i][prev] == INF) continue;
            ll vv = 0;
            rep(k,0,N){
                if(!((prev>>k) & 1)) vv |= (1LL<<k);
            }
            for(ll bit = vv; ; bit = (bit-1) & vv) {

                ll after = (prev | bit);

                ll cnt = __builtin_popcount(after) - __builtin_popcount(prev);
                if(cnt == 0){
                    dp[i+1][after] = min(dp[i+1][after], dp[i][prev] + B[i] * X);
                }else{
                    if(num[bit] < B[i]) continue;
                    dp[i+1][after] = min(dp[i+1][after], dp[i][prev] + (cnt - 1) * Y);
                    
                }
                if(!bit) break;


            }

        }
    }

    ll ans = INF;
    rep(bit,0,(1LL<<N)){
        ans = min(ans, dp[M][bit]);
    }
    print(ans);
}