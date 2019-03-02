#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)
const ll SIZE = 200010;
struct BIT {
	ll bit[SIZE];
	void init(){
		memset(bit,0,sizeof(bit));
	}
	void add(ll k, ll x){
		k++;
		while(k < SIZE){
			bit[k] += x;
			k += k&-k;
		}
	}
	ll get(ll k){
		k++;
		ll ret = 0;
		while(k > 0){
			ret += bit[k];
			k -= k&-k;
		}
		return ret;
	}
	ll get(ll s, ll t){ return get(t) - get(s-1); }

	ll pos(ll k){
		ll l = 0,r = SIZE;
		while(r - l > 1){
			ll m = (l + r) / 2;
			if(get(m) < k) l = m;
			else r = m;
		}
		return r;
	}
};

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    BIT bit;
    ll A[200010];
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) A[i] -= K;
    ll sum[200010] = {};
    rep(i,0,N) sum[i+1] = sum[i] + A[i];
    vector<ll> v;
    rep(i,0,N+1) v.push_back(sum[i]);
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll ans = 0;
    rep(i,0,N+1){
        ll pos = lower_bound(v.begin(), v.end(), sum[i]) - v.begin();
        ans += bit.get(pos);
        bit.add(pos, 1);
    }
    print(ans);
}
