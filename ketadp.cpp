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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

ll solve(ll N){
    if(N == 0) return 0;
    ll dp[20][2][2] = {};
    dp[0][0][0] = 1;
    string sN = to_string(N);
    ll keta = sN.size();
    rep(i,0,keta){
        ll ss = sN[i] - '0';
        rep(j,0,2){
            rep(k,0,2){ // k = 1: 上位の桁でN未満となる値を使った
                ll end = 0;
                if(k == 0){
                    end = ss+1;
                }else{
                    end = 10;
                }
                rep(d,0,end){
                    dp[i+1][j || d == 4 || d == 9][k || d < ss] += dp[i][j][k];
                }

            }
        }
    }
    ll res = dp[keta][1][0] + dp[keta][1][1];
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A,B;
    cin >> A >> B;
    ll ans = solve(B) - solve(A-1);
    print(ans);
}