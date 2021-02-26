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
    string A;
    cin >> A;
    ll N = A.size();
    ll dp[200010];
    rep(i,0,N) dp[i] = INF;
    vector<ll> pos[27];
    rep(i,0,N) pos[A[i]-'a'].push_back(i);
    dp[N] = 1;
    map<ll, pair<char, ll> > restore;
    rrep(i,N-1,0){
        rep(c,0,3){
            ll p = lower_bound(pos[c].begin(), pos[c].end(), i) - pos[c].begin();
            if(p == pos[c].size()){
                if(dp[i] > 1){
                    restore[i] = {(char) ('a' + c), N};
                    dp[i] = 1;
                }
                continue;
            }
            ll nxt = pos[c][p];
            if(dp[i] > dp[nxt+1] + 1){
                restore[i] = {(char)('a' + c), nxt+1};
                dp[i] = dp[nxt+1] + 1;
            }
        }
    }
    string ans = "";
    ll cur = 0;
    while(cur < N){
        auto lp = restore[cur];
        ans += lp.first;
        cur = lp.second;
    }
    print(ans);
}