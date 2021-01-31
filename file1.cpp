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
struct BIT {
private:
    int n,n2;
    vector<ll> bit;

public:
    BIT(ll N){
        n = N;
        bit.assign(n+5, 0);
        n2 = 1;
        while(n2 * 2 <= n) n2 *= 2;
    }

    ll sum(ll x){ //[1, x]
        x++;
        ll res = 0;
        for(ll i = x; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    ll sum(ll lv, ll rv){ // [lv, rv)
        return sum(rv-1) - sum(lv-1);
    }

    void add(ll x, ll v){
        x++;
        for(ll i = x; i <= n; i += i & -i) bit[i] += v;
    }

    ll lower_bound(ll w) {
        if (w <= 0) return 0;
        ll x = 0;
        for (ll k = n2; k > 0; k /= 2) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    BIT bit(20);
    bit.add(0,1);
    bit.add(0,1);
    bit.add(2,1);
    bit.add(3,1);
    print(bit.lower_bound(5));
    // ll Q;
    // cin >> Q;
    // BIT bit(200010);
    // while(Q--){
    //     ll T,X;
    //     cin >> T >> X;
    //     if(T == 1){
    //         bit.add(X, 1);
    //     }else{
    //         ll pos = bit.lower_bound(X);
    //         print(pos);
    //         bit.add(pos, -1);
    //     }
    // }
    
}