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
        ll A, B;
        cin >> A >> B;
        ll lv = 1, rv = max(A,B) * 3;
        if(A == B){
            print(2*(A-1));
            continue;
        }
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            ll a1 = (mid + 1) / 2;
            ll b1 = mid + 1 - a1;
            if(a1 * b1 <= A*B-1){
                lv = mid;
            }else{
                rv = mid;
            }
        }
        print(lv - 1);
    }
    
}
