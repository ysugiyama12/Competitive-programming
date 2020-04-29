/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(int i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
int dp[2010][2010] = {};
int nxt_s[2010][30] = {};
int nxt_t[2010][30] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    string T = S;
    reverse(T.begin(), T.end());
    vector<int> pos_s[30], pos_t[30];
    ll N = S.size();
    rep(i,0,N) pos_s[S[i]-'a'].push_back(i);
    rep(i,0,N) pos_t[T[i]-'a'].push_back(i);
    memset(nxt_s, -1, sizeof(nxt_s));
    memset(nxt_t, -1, sizeof(nxt_t));

    dp[0][0] = 1;
    rrep(i,N-1,0){
        rep(k,0,26){
            nxt_s[i][k] = nxt_s[i+1][k];
        }
        nxt_s[i][S[i]-'a'] = i;
    }
    rrep(i,N-1,0){
        rep(k,0,26){
            nxt_t[i][k] = nxt_t[i+1][k];
        }
        nxt_t[i][T[i]-'a'] = i;
    }


    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,26){
                ll ps = nxt_s[i][k];
                ll pt = nxt_t[j][k];
                if(ps != -1 && pt != -1){
                    if(ps + pt + 2 <= N){
                        dp[ps+1][pt+1] += dp[i][j];
                        dp[ps+1][pt+1] %= MOD;
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i,0,N+1){
        rep(j,0,N+1){
            if(dp[i][j] != 0 && i + j <= N){
                ll cnt = 0;
                ll lv = i, rv = N-1-j;
                rep(k,0,26){
                    ll p = upper_bound(pos_s[k].begin(), pos_s[k].end(), rv) - pos_s[k].begin();
                    ll p2 = lower_bound(pos_s[k].begin(), pos_s[k].end(), lv) - pos_s[k].begin();
                    if(p - p2 > 0) cnt++;
                }
                ans += dp[i][j] * (cnt+1);
                ans %= MOD;

            }

        }
    }
    ans--;
    print(ans);

}