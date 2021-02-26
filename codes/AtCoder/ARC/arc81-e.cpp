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
// struct BIT { //1-indexed
// private:
//     int n,n2;
//     vector<ll> bit;

// public:
//     BIT(ll N){
//         n = N;
//         bit.assign(n+1, 0);
//         n2 = 1;
//         while(n2 * 2 <= n) n2 *= 2;
//     }

//     ll sum(ll x){ //[1, x]
//         ll res = 0;
//         for(ll i = x; i > 0; i -= i & -i) res += bit[i];
//         return res;
//     }

//     ll sum(ll lv, ll rv){ // [lv, rv)
//         return sum(rv-1) - sum(lv-1);
//     }

//     void add(ll x, ll v){
//         if(x == 0) return;
//         for(ll i = x; i <= n; i += i & -i) bit[i] += v;
//     }

//     ll lower_bound(ll w) {
//         if (w <= 0) return 0;
//         ll x = 0;
//         for (ll k = n2; k > 0; k /= 2) {
//             if (x + k <= n && bit[x + k] < w) {
//                 w -= bit[x + k];
//                 x += k;
//             }
//         }
//         return x + 1;
//     }
// };

struct SegmentTreeMin {
private:
    int n;
    vector<ll> node;

public:
    SegmentTreeMin(ll N){
        ll sz = N;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        rep(i,0,sz) node[i+n-1] = INF;
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

    ll getsum(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string A;
    cin >> A;
    ll N = A.size();
    ll ans = 0;
    ll dp[200010] = {};
    dp[0] = 1;
    vector<ll> pos[27];
    rep(i,0,N){
        pos[A[i] - 'a'].push_back(i);
    }
    // bool kubaru = false;
    // if(kubaru){
    rep(i,0,N){
        rep(j,0,26){
            ll p = upper_bound(pos[j].begin(), pos[j].end(), i-1) - pos[j].begin();
            if(p == pos[j].size()) continue;
            dp[pos[j][p] + 1] += dp[i];
            dp[pos[j][p] + 1] %= MOD;
        }
    }
    // printa(dp, N+1);
    ll res = 0;
    rep(i,0,N+1){
        res += dp[i];
        res %= MOD;
    }
    print(res);

// }else{
    // BIT bit(200010);
    SegmentTreeMin sg(200010);
    sg.add(1,1);
    // bit.add(1,1);
    rep(i,0,N){
        ll j = A[i] - 'a';
        ll p = lower_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
        if(p == 0){
            // ll val = bit.sum(1, i+2);
            ll val = sg.getsum(1, i+2);
            // print(val);
            // bit.add(i+2, val);
            sg.add(i+2, val);
        }else{
            // ll val = bit.sum(pos[j][p-1]+2, i+2);
            ll val = sg.getsum(pos[j][p-1] + 2,)
            bit.add(i+2, val);
        }
    }
    // rep(i,0,N){
    //     dp[i+1] += dp[0];
    //     rep(j,0,26){
    //         ll p = lower_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
    //         if(p == 0) continue;
    //         ll idx = pos[j][p-1];
    //         dp[i+1] += dp[idx+1];
    //     }
    // }
    res = 0;
    rep(i,0,N+1) res += bit.sum(i+1, i+2);
    print(res);
    // }

}