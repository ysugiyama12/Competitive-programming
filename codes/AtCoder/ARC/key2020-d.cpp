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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[20], B[20];
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) cin >> B[i];
    ll ans = INF;
    if(N == 1){
        print(0);
        return 0;
    }
    rep(bit,0,(1LL<<N)){
        vector<ll> tt;
        rep(i,0,N){ // 0が上
            tt.push_back((bit>>i) & 1);
        }
        ll cnt_even = 0, cnt_odd = 0;
        rep(i,0,N){
            if(tt[i] == 0){
                if(i % 2 == 0){
                    cnt_even++;
                }else{
                    cnt_odd++;
                }
            }else{
                if(i % 2 == 0){
                    cnt_odd++;
                }else{
                    cnt_even++;
                }
            }
        }
        if(N % 2 == 0){
            if(cnt_odd != cnt_even) continue;
        }else{
            if(cnt_even != cnt_odd+1) continue;
        }
        // printa(tt, N);
        vector<lpair> odd, even;

        rep(i,0,N){
            if(tt[i] == 0 && i % 2 == 0){
                even.push_back({A[i], i});
            }else if(tt[i] == 0 && i % 2 == 1){
                odd.push_back({A[i], i});
            }else if(tt[i] == 1 && i % 2 == 0){
                odd.push_back({B[i], i});
            }else{
                even.push_back({B[i], i});
            }
        }
        sort(even.begin(), even.end(), [](lpair l1, lpair l2){
            if(l1.first == l2.first){
                return l1.second < l2.second;
            }
            return l1.first < l2.first;
        });
        sort(odd.begin(), odd.end(), [](lpair l1, lpair l2){
            if(l1.first == l2.first){
                return l1.second < l2.second;
            }
            return l1.first < l2.first;
        });

        bool ok = true;
        ll se = even.size(), so = odd.size();
        // rep(i,0,se){
        //     print(even[i].first, even[i].second);
        // }
        // rep(i,0,so){
        //     print(odd[i].first, odd[i].second);
        // }
        rep(i,0,se-1){
            if(even[i].first > odd[i].first) ok = false;
        }
        rep(i,0,so-1){
            if(odd[i].first > even[i+1].first) ok = false;
        }
        if(N % 2 == 0){
            if(even[se-1].first > odd[so-1].first) ok = false;
        }
        if(N % 2 == 1){
            if(odd[so-1].first > even[so].first) ok = false;
        }
        // print(ok);
        if(not ok) continue;
        vector<ll> v2;
        rep(i,0,so){
            v2.push_back(even[i].second);
            v2.push_back(odd[i].second);
        }
        if(N % 2 == 1) v2.push_back(even[se-1].second);
        // if(bit == 0) printa(v2, N);
        BIT bb(20);
        ll tentou = 0;
        rep(i,0,N){
            tentou += bb.sum(v2[i]+1);
            bb.add(v2[i]+1, 1);
        }
        tentou = N * (N-1) / 2 - tentou;
        ans = min(ans, tentou);

    }
    if(ans == INF){
        print(-1);
    }else{
        print(ans);
    }


    

}