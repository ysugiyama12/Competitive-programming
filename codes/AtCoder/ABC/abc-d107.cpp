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
struct BIT { //1-indexed
private:
    int n,n2;
    vector<ll> bit;

public:
    BIT(ll N){
        n = N;
        bit.assign(n+1, 0);
        n2 = 1;
        while(n2 * 2 <= n) n2 *= 2;
    }

    ll sum(ll x){ //[1, x]
        ll res = 0;
        for(ll i = x; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    ll sum(ll lv, ll rv){ // [lv, rv)
        return sum(rv-1) - sum(lv);
    }

    void add(ll x, ll v){
        if(x == 0) return;
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
        return x + 1;
    }
};

struct SegmentTreeMin {
private:
    int n;
    vector<ll> node;

public:
    SegmentTreeMin(ll N){
        ll sz = N;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);

        rep(i,0,sz) node[i+n-1] = 0;
        rrep(i,n-2,0) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(ll x, ll val){
        x += (n-1);
        node[x] = val;
        while(x > 0){
            x = (x-1)/2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

	void add(ll x, ll val){
		x += n-1;
		node[x] += val;
        while(x > 0){
            x = (x-1)/2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
	}

    ll getMin(ll a, ll b){
        ll res = INF;
        a += n; b += n;
        while(a < b){
            if(b & 1){
                b -= 1;
                res = min(res, node[b-1]);
            }
            if(a & 1){
                res = min(res, node[a-1]);
                a++;
            }
            a >>= 1; b >>= 1;
        }
        return res;
    }

    ll getSum(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getSum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getSum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll lv = 0, rv = 1e9+7;
    ll M = N * (N+1) / 2;
    while(rv - lv > 1){
        ll x = (rv + lv) / 2;
        ll B[100010];
        rep(i,0,N){
            if(A[i] >= x){
                B[i] = 1;
            }else{
                B[i] = -1;
            }
        }
        ll S[100010] = {};
        S[0] = 100000;
        rep(i,0,N) S[i+1] = S[i] + B[i];
        SegmentTreeMin sg(200010);
        // rep(i,0,200010) sg.update(i,0);
        ll val = 0;
        rep(i,0,N+1){
            val += sg.getSum(1, S[i]+1);
            print(val);
            sg.add(S[i], 1);
        }
        if(val >= (M+1)/2) {
            lv = x;
        }else{
            rv = x;
        }
    }
    print(lv);
}