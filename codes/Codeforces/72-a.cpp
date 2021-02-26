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
    ll T;
    cin >> T;
    while(T--){
        ll S,I,E;
        cin >> S >> I >> E;
        ll lv = -1, rv = E+1;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            ll amari = E - mid;
            ll ss = S + mid;
            ll ii = I + amari;
            if(ss > ii){
                rv = mid;
            }else{
                lv = mid;
            }
        }
        print(E - rv + 1);
    }
    
}