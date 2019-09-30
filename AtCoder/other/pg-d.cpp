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

bool comp(P p1, P p2){
    if(p1.x == p2.x){
        if(p1.y == p2.y){
            return p1.z > p2.z;
        }
        return p1.y > p2.y; 
    }
    return p1.x < p2.x;
}

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[100010], y[100010], z[100010];
    rep(i,0,N) cin >> x[i] >> y[i] >> z[i];
    vector<ll> X,Y,Z;
    X.push_back(0);
    Y.push_back(0);
    Z.push_back(0);
    rep(i,0,N){
        X.push_back(x[i]);
        Y.push_back(y[i]);
        Z.push_back(z[i]);
    }
    X.push_back(INF);
    Y.push_back(INF);
    Z.push_back(INF);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    Z.erase(unique(Z.begin(), Z.end()), Z.end());
    rep(i,0,N){
        x[i] = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
        y[i] = lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();
        z[i] = lower_bound(Z.begin(), Z.end(), z[i]) - Z.begin();
    }


    vector<P> za;
    rep(i,0,N){
        za.push_back((P){x[i], y[i], z[i], i});
    }
    sort(za.begin(), za.end(), comp);
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
        // ll now_val = sg.getMin(za[i].y, za[i].y+1);
        // ll diff = za[i].z - now_val;
        // if(diff < 0){
        //     sg.update(za[i].y, diff);
        // }
    }
    rep(i,0,N){
        if(ans[i] == 1){
            print("Yes");
        }else{
            print("No");
        }
    }

    
}