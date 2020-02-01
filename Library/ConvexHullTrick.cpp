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

struct ConvexHullTrick {
    vector<lpair> deq;
    ll s,t;
    ConvexHullTrick(ll n){
        deq.resize(n);
        s = 0, t = 0;
    }
    void add(ll a, ll b) {
        const lpair p(a,b);
        while(s+1 < t && check(deq[t-2],deq[t-1],p)) t--;
        deq[t++] = p;
    }
    ll incl_query(ll x) {
        while(s+1 < t && f(deq[s], x) >= f(deq[s+1], x)) s++;
        return f(deq[s], x);
    }
    ll query(ll x) {
        ll low = s-1, high = t-1;
        while(high - low > 1) {
            ll mid = (low+high) / 2;
            if (isright(deq[mid], deq[mid+1], x)) low = mid;
            else high = mid;
        }
        return f(deq[high], x);
    }
private:
    bool isright(const lpair &p1, const lpair &p2, ll x) {
        return (p1.second - p2.second) >= x * (p2.first - p1.first);
    }
    bool check(const lpair &p1, const lpair &p2, const lpair &p3) {
        return (p2.first - p1.first) * (p3.second - p2.second) >=
            (p2.second - p1.second) * (p3.first - p2.first);
        }
    ll f(const lpair &p, ll x) {
        return p.first * x + p.second;
    }
};

// verify: https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[200010];
    rep(i,0,N) cin >> a[i];
    ConvexHullTrick cht(200010);

    rep(i,0,N){
        cht.add(-2 * (i+1), a[i] + (i+1) * (i+1));
    }
    rep(i,0,N){
        ll v = cht.query(i+1);
        print(v + (i+1) * (i+1));
    }
}