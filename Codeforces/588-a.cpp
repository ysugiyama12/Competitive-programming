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
    ll a[4];
    rep(i,0,4) cin >> a[i];
    ll v = 0;
    rep(i,0,4) v += a[i];
    rep(bit,0,(1<<4)){
        ll sum = 0;
        rep(i,0,4){
            if((bit>>i) & 1) sum += a[i];
        }
        if(sum + sum == v){
            print("YES");
            return 0;
        }
    }
    print("NO");
    
}