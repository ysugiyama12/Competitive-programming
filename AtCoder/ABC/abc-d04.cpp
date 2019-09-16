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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R,G,B;
    cin >> R >> G >> B;
    ll ans = INF;
    rep(lv,-300, 301){
        ll val = 0;
        ll rv = lv + G - 1;// G: [lv, rv]
        rep(i,lv, rv+1) val += abs(i);
        if(lv <= -100){
            for(ll i = lv-1; i >=lv-R; i--) val += abs(i+100);
        }else{
            ll left_amari = lv + 100-1;
            ll tt = (R-1) / 2;
            if(tt <= left_amari){
                val += tt * (tt+1) / 2;
                val += (R-1-tt) * (R-1-tt+1) / 2;
            }else{
                val += left_amari * (left_amari + 1) / 2;
                val += (R-1-left_amari) * (R-left_amari) / 2;
            }
        }
        
        if(rv >= 100){
            for(ll i = rv+1; i < rv+1+B; i++) val += abs(i-100);
        }else{
            ll right_amari = 100 - rv - 1;
            ll tt = (B - 1) / 2;
            if(tt <= right_amari){
                val += tt * (tt + 1) / 2;
                val += (B-1-tt) * (B-tt) / 2;
            }else{
                val += right_amari * (right_amari+1) / 2;
                val += (B-1-right_amari) * (B-right_amari) / 2;
            }
        }
        ans = min(ans, val);
    }
    print(ans);

}