/*** author: yuji9511 ***/
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using mint = modint;

void solve(){
    ll N,K,MOD;
    cin >> N >> K >> MOD;
    mint::set_mod(MOD);

    vector<mint> ans(N+1, 0);
    ans[1] = ans[N] = K;
    ll max_val = N * (N+1) / 2 * K;
    vector<vector<mint> > dp(N+1, vector<mint> (max_val+10, 0));
    dp[0][0] = 1;
    vector<vector<mint> > sum;

    rep(i,0,N){
        sum.assign(i+1, vector<mint> (max_val / (i+1) + 10, 0));
        rep(j,0,max_val+1){
            ll amari = j % (i+1);
            ll idx = j / (i+1);
            sum[amari][idx+1] += sum[amari][idx] + dp[i][j];
        }
        rep(j,0,max_val+1){
            ll amari = j % (i+1);
            ll idx1 = j / (i+1);
            ll idx2 = 0;
            if(j - K * (i+1) >= 0){
                idx2 = (j - K * (i+1)) / (i+1);
            }
            dp[i+1][j] += sum[amari][idx1+1] - sum[amari][idx2];
        }
    }
    rep(x,2,N){
        rep(i,0,max_val+1){
            ans[x] += dp[x-1][i] * dp[N-x][i] *(K+1);
        }
        ans[x]--;
    }
    rep(i,1,N+1) print(ans[i].val());
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}