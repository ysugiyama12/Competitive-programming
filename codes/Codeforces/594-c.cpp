/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  ll sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(ll n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1LL;
    seg.assign(2 * sz, M1);
  }

  void set(ll k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(ll k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(ll k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1LL) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(ll a, ll b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const ll &k) const {
    return seg[k + sz];
  }

  template< typename C >
  ll find_subtree(ll a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }


  template< typename C >
  ll find_first(ll a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    ll b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1LL) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  ll find_last(ll b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1LL, check, R, true);
      return -1;
    }
    ll a = sz;
    for(b += sz; a < b; a >>= 1LL, b >>= 1LL) {
      if(b & 1LL) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,P;
    cin >> N >> P;
    ll t[100010];
    rep(i,0,N) cin >> t[i];
    ll min_val = INF;
    SegmentTree< ll > seg(N+10, [](ll a, ll b) { return min(a, b); }, INF);
    rep(i,0,N){
        seg.update(i+1, t[i]);
    }
    ll now = 0;
    ll ans[100010] = {};
    ll last = -1;
    queue<ll> que;
    rep(i,0,N){
        ll res = seg.query(1,N+1);
        if(res > now) now += res - now;
        ll pos = 0;
        if(last == -1){
            pos = seg.find_first(1, [&](ll a) { return (a - now <= 0); });
            last = pos;
        }else{
            pos = seg.find_first(last, [&](ll a) { return (a - now <= 0); });
        }
        
        now += P;
        ans[pos-1] = now;
        seg.update(pos, INF);
    }
    printa(ans, N);

}