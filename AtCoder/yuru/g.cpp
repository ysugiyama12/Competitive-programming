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
        node.resize(2*n-1, 0);

        rep(i,0,sz) node[i+n-1] = v[i];
        rrep(i,n-2,0) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(ll x, ll val){
        x += (n-1);
        node[x] = val;
        while(x > 0){
            x = (x-1)/2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    ll getMax(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getMax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getMax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll F[100010], B[100010];
    rep(i,0,N) cin >> F[i];
    rep(i,0,N) cin >> B[i];
    SegmentTree seg(vector<ll>(N, 0));
    rep(i,0,N){
        seg.update(i, B[i]);
    }
    ll ans = 0;
    rep(i,0,N){
        ans = max(ans, F[i] + seg.getMax(max(0LL, i-K), min(N, i+K+1)));
    }
    print(ans);


}
