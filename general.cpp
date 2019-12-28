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
ll M,N;
string S,T;
ll calc(ll si, ll ti){
    bool dp[55][55] = {};
    dp[si][ti] = true;
    rep(i,si,M+1){
        rep(j,ti,N+1){
            if(not dp[i][j]) continue;
            // print(i,j);

            ll sum = i - si+ j - ti;
            if(sum % 2 == 0){
                if(S[i] == 'I'){
                    dp[i+1][j] = true;
                }
                if(T[j] == 'I'){
                    dp[i][j+1] = true;
                }
            }else{
                if(S[i] == 'O'){
                    dp[i+1][j] = true;
                }
                if(T[j] == 'O'){
                    dp[i][j+1] = true;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,si,M+1){
        rep(j,ti,N+1){
            if(dp[i][j]) ans = max(ans, i - si+j - ti);
        }
    }
    if(ans > 0 && ans % 2 == 0) ans--;
    return ans;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> M >> N;
    cin >> S >> T;
    // if(N > 50 || M > 50) return 0;
    // bool dp[2010][2010] = {};
    S += '?';
    T += '?';
    // dp[0][0] = true;
    ll ans = 0;
    rep(i,0,M){
        rep(j,0,N){
            ll res = calc(i,j);
            ans = max(ans, res);
        }
    }
    print(ans);
    print(abs(ans - 2));
}
