/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll dp[100010][81] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll x[85], s[85];
    rep(i,0,N) cin >> x[i] >> s[i];
    rep(i,0,M+1){
        rep(j,0,N+1){
            dp[i][j] = INF; 
        }
    }
    vector<lpair> lp;
    rep(i,0,N) lp.push_back({x[i], s[i]});
    sort(lp.begin(), lp.end()); 
    rep(i,0,N){
        dp[1][i] = max(0LL, abs(lp[i].first - 1) - lp[i].second);
    }

    rep(m,2,M+1){
        rep(j,0,N){
            rep(k,0,j+1){
                if(j == k){
                    ll diff =  m - lp[j].first;
                    if(diff > 0){
                        ll v2 = lp[j].first - diff;
                        if(v2 >= 1){
                            dp[m][j] = min(dp[m][j], dp[v2][j]);
                        }else{
                            if(m - lp[j].first > lp[j].second){
                                dp[m][j] = min(dp[m][j], dp[m-1][j] + 1);
                            }else{
                                dp[m][j] = min(dp[m][j], dp[m-1][j]);
                            }
                        }
                    }else{
                        dp[m][j] = min(dp[m][j], dp[m-1][j]);
                    }
                }else{
                    ll diff = max(0LL, abs(m - lp[j].first) - lp[j].second);
                    dp[m][j] = min(dp[m][j], dp[m-1][k] + diff);
                }
            }

        }
    }
    ll ans = INF;
    rep(i,0,N) ans = min(ans, dp[M][i]);
    print(ans);


    

}