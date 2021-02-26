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
ll dp[210][210] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    ll ns = s.size();
    ll nt = t.size();
    rep(i,0,ns){
        rep(j,0,nt){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    // print(dp[ns][nt]);
    // 文字列の決定
    string ans = "";
    ll px = ns, py = nt;
    while(px+py){
        if(px && dp[px-1][py] == dp[px][py]){
            px--;
        }else if(py && dp[px][py-1] == dp[px][py]){
            py--;
        }else{
            px--; py--; ans += s[px];
        }
    }
    reverse(ans.begin(), ans.end());
    print(ans);

}