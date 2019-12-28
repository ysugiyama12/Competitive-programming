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
ll sum[27][200010] = {};
ll dp[200010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    vector<ll> pos[27];
    rep(i,0,N) pos[S[i]-'a'].push_back(i);
    rep(i,0,N){
        rep(c,0,26){
            if(c == S[i] - 'a'){
                sum[c][i+1] += sum[c][i] + 1;
            }else{
                sum[c][i+1] += sum[c][i];
            }
        }
    }
    dp[0] = 0;
    rep(i,0,N) dp[i+1] = INF;
    rep(i,0,N){
        rep(j,0,i+1){
            ll odd_cnt = 0;
            rep(k,0,26){
                if((sum[k][i+1] - sum[k][j]) % 2 == 1) odd_cnt++;
            }
            if(odd_cnt <= 1){
                dp[i+1] = min(dp[i+1], dp[j] + 1);
            }
        }
    }
    print(dp[N]);
    

}