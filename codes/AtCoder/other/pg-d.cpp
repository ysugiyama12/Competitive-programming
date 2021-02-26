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
#define print(x) cout << (x) << endl;
#define print2(x, y) cout << (x) << " " << (y) << endl;
typedef struct {
    ll x;
    ll y;
    ll z;
    ll idx;
} P;

struct SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v){
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        rep(i,0,sz) node[i+n-1] = v[i];
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

    ll getMin(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];
        ll vl = getMin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getMin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

vector<ll> compress(vector<ll> x, ll n){
	vector<ll> v;
	v.push_back(-INF); v.push_back(INF);
	rep(i,0,n) v.push_back(x[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<ll> res;
	rep(i,0,n) res.push_back(lower_bound(v.begin(), v.end(), x[i]) - v.begin());
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> x(N), y(N), z(N);
    rep(i,0,N) cin >> x[i] >> y[i] >> z[i];
    x = compress(x, N);
    y = compress(y, N);
    z = compress(z, N);

    vector<P> za;
    rep(i,0,N){
        za.push_back((P){x[i], y[i], z[i], i});
    }

    sort(za.begin(), za.end(), [](P p1, P p2){
        if(p1.x == p2.x){
            if(p1.y == p2.y){
                return p1.z > p2.z;
            }
            return p1.y > p2.y; 
        }
        return p1.x < p2.x;
    });

    SegmentTree sg(vector<ll>(100010, INF));
    ll ans[100010] = {};

    rep(i,0,N){
        ll v = sg.getMin(0, za[i].y);
        if(v < za[i].z){
            ans[za[i].idx] = 1;
        }else{
            ans[za[i].idx] = 0;
        }
        ll now_val = sg.getMin(za[i].y, za[i].y+1);
        sg.update(za[i].y, min(za[i].z, now_val));
    }
    rep(i,0,N){
        if(ans[i] == 1){
            print("Yes");
        }else{
            print("No");
        }
    }
}