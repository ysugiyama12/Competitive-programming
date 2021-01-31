/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = int;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
// const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
vector<vll> dp;

void solve(){
    ll N;
    cin >> N;
    ll M = N*N;
    dp.assign(1LL<<M, vll(M, 0));
    dp[1][0] = 1;
    rep(bit,0,(1LL<<M)){
        print()
        rep(cur,0,M){
            rep(nxt,0,M){
                if(bit & (1LL<<nxt)) continue;
                ll ch = cur/N, cw = cur%N;
                ll nh = nxt/N, nw = nxt%N;
                if((ch == nh && abs(cw - nw) == 1) || (cw == nw && abs(ch - nh) == 1)){
                    dp[bit | (1LL<<nxt)][nxt] += dp[bit][cur];
                }
            }
        }
    }
    ll ans = 0;
    rep(bit,0,1LL<<M){
        ans += dp[bit][M-1];
    }
    print(ans);
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}