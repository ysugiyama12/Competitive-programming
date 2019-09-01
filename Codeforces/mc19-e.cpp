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

// Segment Tree(min)
struct SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v){
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

ll L[1000010];
vector<ll> a[1000010];
vector<SegmentTree> st;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,W;
    cin >> N >> W;
    rep(i,0,N){
        cin >> L[i];
        rep(j,0,L[i]){
            ll tmp;
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }
    rep(i,0,N){
        SegmentTree tt(a[i]);
        st.push_back(tt);
    }
    rep(w,0,W){
        ll ans = 0;
        rep(n,0,N){
            ll width = min(L[n], W - L[n]+1);
            ll dist = min(w+1, W-w);
            ll cnt = min(dist, width);
            ll right_pos = 0;
            if(w+1 <= L[n]){
                right_pos = w+1;
            }else{
                right_pos = L[n];
            }
            ll max_val = st[n].getMax(right_pos-cnt, right_pos);
            if(max_val < 0){
                if(dist <= W-L[n]){
                    max_val = 0;
                }
            } 
            ans += max_val;
        }
        cout << ans << " \n"[w==W-1];
    }


    
}