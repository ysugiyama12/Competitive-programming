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
struct BIT { //1-indexed
private:
    int n,n2;
    vector<ll> bit;

public:
    BIT(vector<ll> v){
        n = v.size();
        rep(i,0,n) bit.push_back(v[i]);
        n2 = 1;
        while(n2 * 2 <= n) n2 *= 2;
    }

    ll sum(ll i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(ll i, ll x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
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
        return x + 1;
    }

};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    ll T[200010], X[200010];
    rep(i,0,Q) cin >> T[i] >> X[i];
    vector<ll> t(200010, 0);
    BIT bit(t);
    rep(i,0,Q){
        if(T[i] == 1){
            bit.add(X[i], 1);
        }else{
            ll v = bit.lower_bound(X[i]);
            print(v);
            bit.add(v, -1);
        }
    }
}