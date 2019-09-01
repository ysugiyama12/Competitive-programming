/*** author: yuji9511 ***/
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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll nth(ll num, ll n){
    return (num >> n) & 1;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll L,R;
    cin >> L >> R;
    ll dp[65][2][3] = {};
    string sr = to_string(R);
    dp[0][0][0] = 1;
    ll keta = 60;
    rep(i,0,keta){
        ll ss = ()
    }
    
    // rrep(i,59,0){
    //     rep(s,0,3){
    //         ll k = nth(R, i);


    //     }
    // }
    // ll ans = 0;
    // rep(x,L,R+1){
    //     rep(y,x,R+1){
    //         if(y % x == (y ^ x)){
    //             if(y -  x != y % x) print2(x,y);
    //             print2(x,y);
    //             ans++;
    //         }
    //     }
    // }
    // print(ans);

    
}