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

struct SegmentTree2 {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree2(vector<ll> v){
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, -INF);

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
        if(r <= a || b <= l) return -INF;
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
    ll P[200010];
    rep(i,0,N) cin >> P[i];
    SegmentTree sg_min(vector<ll>(200010));
    SegmentTree2 sg_max(vector<ll>(200010));
    rep(i,0,N){
        sg_min.update(i, P[i]);
        sg_max.update(i, P[i]);
    }
    ll ans = N-K+1;
    ll kk = K-1;
    vector<ll> v;
    ll cnt = 0;
    rep(i,0,N-1){
        if(P[i] < P[i+1]){
            cnt++;
        }else{
            v.push_back(cnt);
            cnt = 0;
        }
    }
    v.push_back(cnt);
    ll val = 0;
    for(auto &e: v){
        if(e >= K-1){
            val++;
        }
    }

    rep(i,0,N-kk+1){
        if(i == 0 || i == N-kk) continue;
        ll max_val = sg_max.getMax(i, i+kk);
        ll min_val = sg_min.getMin(i, i+kk);
        if(P[i-1] < min_val && P[i+kk] > max_val) ans--;
    }
    if (val > 0) ans -= (val-1);
    print(ans);
    

    
}