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
    ll Q;
    cin >> Q;
    while(Q--){
        ll C,M,X;
        cin >> C >> M >> X;
        ll lv = 0, rv = 1e8+10;
        while(rv - lv > 1){
            ll c = C, m = M, x = X;
            ll mid = (rv + lv) / 2;
            c -= mid; m -= mid;
            if(c >= 0 && m >= 0 && c+m+x >= mid){
                lv = mid;
            }else{
                rv = mid;
            }
        }
        print(lv);
    }
}