/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
void print() {}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail){ cout << head << " \n"[sizeof...(tail) == 0]; print(forward<Tail>(tail)...);}
ll power(ll x, ll n){
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1) res = res * x % MOD;
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W;
    cin >> H >> W;
    ll r[1010], c[1010];
    rep(i,0,H) cin >> r[i];
    rep(i,0,W) cin >> c[i];
    ll ans = 1;
    ll check[1010][1010] = {};
    bool ok = true;
    rep(i,0,H){
        rep(j,0,r[i]){
            check[i][j] = 1;
        }
        check[i][r[i]] = 2;
    }
    rep(j,0,W){
        rep(i,0,c[j]){
            if(check[i][j] == 0){
                check[i][j] = 1;
            }else if(check[i][j] == 1){

            }else{
                ok = false;
            }
        }
        if(check[c[j]][j] == 0){
            check[c[j]][j] = 2;
        }else if(check[c[j]][j] == 1){
            ok = false;
        }else{
            check[c[j]][j] = 2;
        }

    }
    if(not ok){
        print(0);
        return 0;
    }
    ll cnt = 0;
    rep(i,0,H){
        rep(j,0,W){
            if(check[i][j] == 0) cnt++;
        }
    }
    ans *= power(2, cnt);
    print(ans);
}