#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

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
    // SegmentTree seg(vector<ll> (N, INF));

}