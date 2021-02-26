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
// getMax
struct SegmentTreeMax {
private:
    int n;
    vector<ll> node;

public:
    SegmentTreeMax(ll N){
        ll sz = N;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, -INF);

        rep(i,0,sz) node[i+n-1] = -INF;
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

	void add(ll x, ll val){
		x += n-1;
		node[x] += val;
        while(x > 0){
            x = (x-1)/2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
	}

    ll getMax(ll a, ll b){
        ll res = -INF;
        a += n; b += n;
        while(a < b){
            if(b & 1){
                b -= 1;
                res = max(res, node[b-1]);
            }
            if(a & 1){
                res = max(res, node[a-1]);
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
    ll N;
    cin >> N;
    ll a[(1LL<<18) + 2];
    rep(i,0,N) cin >> a[i];
    ll cur = -1;
    rep(i,0,N){
        if(a[i] == -1){
            cur = i;
            break;
        }
    }
    rep(i,0,cur) a[i] = 0;
    ll ans = 0;
    SegmentTreeMax sg((1LL<<18) + 7);
    rep(i,0,N) sg.update(i, a[i]);
    ll 


    

}