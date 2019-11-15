/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

struct SegmentTreeMin {
private:
    int n;
    vector<ll> node;

public:
    SegmentTreeMin(ll N){
        ll sz = N;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        rep(i,0,sz) node[i+n-1] = (1LL<<31)-1;
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

    // ll getMin(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
    //     if(r < 0) r = n;
    //     if(r <= a || b <= l) return INF;
    //     if(a <= l && r <= b) return node[k];
    //     ll vl = getMin(a, b, 2*k+1, l, (l+r)/2);
    //     ll vr = getMin(a, b, 2*k+2, (l+r)/2, r);
    //     return min(vl, vr);
    // }
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
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q;
    cin >> N >> Q;
    SegmentTreeMin sg(100010);
    rep(i,0,Q){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 0){
            sg.update(b, c);
        }else{
            print(sg.getMin(b, c+1));
        }
    }
    
    

}