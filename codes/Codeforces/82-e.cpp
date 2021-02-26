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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll tt;
    cin >> tt;
    while(tt--){
        string S,T;
        cin >> S >> T;
        bool ok = false;
        ll ns = S.size(), nt = T.size();
        ll pos = 0;
        rep(i,0,ns){
            if(pos == nt) break;
            if(S[i] == T[pos]) pos++;
        }
        if(pos == nt) ok = true;
        rep(i,0,pos){
            ll sz1 = i+1, sz2 = nt - sz1;
            vector<ll> dp(sz1+1, 0);
            rep(j,1,sz1+1) dp[j] = -1; 
            dp[0] = 0;
            rep(j,0,ns){
                rrep(k,sz1,0){
                    if(dp[k] == -1) continue;
                    if(S[j] == T[k] && k != sz1){
                        dp[k+1] = max(dp[k+1], dp[k]);
                    }
                    if(S[j] == T[sz1+dp[k]] && dp[k] != sz2){
                        dp[k]++;
                    }
                }
            }
            if(dp[sz1] == sz2) ok = true;
        }
        if(ok) {
            print("YES");
        }else{
            print("NO");
        }
    }
}