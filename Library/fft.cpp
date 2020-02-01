//*** author: yuji9511 ***/
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
namespace FastFourierTransform {
  using real = double;
  struct C {
    real x, y;
    C() : x(0), y(0) {}
    C(real x, real y) : x(x), y(y) {}
    inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }
    inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }
    inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }
    inline C conj() const { return C(x, -y); }
  };

  const real PI = acosl(-1);
  ll base = 1;
  vector< C > rts = { {0, 0},
                     {1, 0} };
  vector< ll > rev = {0, 1};


  void ensure_base(ll nbase) {
    if(nbase <= base) return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for(ll i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    while(base < nbase) {
      real angle = PI * 2.0 / (1 << (base + 1));
      for(ll i = 1 << (base - 1); i < (1 << base); i++) {
        rts[i << 1] = rts[i];
        real angle_i = angle * (2 * i + 1 - (1 << base));
        rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
      }
      ++base;
    }
  }

  void fft(vector< C > &a, ll n) {
    assert((n & (n - 1)) == 0);
    ll zeros = __builtin_ctz(n);
    ensure_base(zeros);
    ll shift = base - zeros;
    for(ll i = 0; i < n; i++) {
      if(i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for(ll k = 1; k < n; k <<= 1) {
      for(ll i = 0; i < n; i += 2 * k) {
        for(ll j = 0; j < k; j++) {
          C z = a[i + j + k] * rts[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  vector< ll > multiply(const vector< ll > &a, const vector< ll > &b) {
    ll need = (ll) a.size() + (ll) b.size() - 1;
    ll nbase = 1;
    while((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    ll sz = 1 << nbase;
    vector< C > fa(sz);
    for(ll i = 0; i < sz; i++) {
      ll x = (i < (ll) a.size() ? a[i] : 0);
      ll y = (i < (ll) b.size() ? b[i] : 0);
      fa[i] = C(x, y);
    }
    fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for(ll i = 0; i <= (sz >> 1); i++) {
      ll j = (sz - i) & (sz - 1);
      C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
      fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
      fa[i] = z;
    }
    for(ll i = 0; i < (sz >> 1); i++) {
      C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
      C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
      fa[i] = A0 + A1 * s;
    }
    fft(fa, sz >> 1);
    vector< ll > ret(need);
    for(ll i = 0; i < need; i++) {
      ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
    }
    return ret;
  }
};


// verify: https://atcoder.jp/contests/atc001/tasks/fft_c
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll nn = 1;
    while(nn < N) nn *= 2;
    vector<ll> a(nn+1), b(nn+1);
    rep(i,0,N){
        ll t1,t2;
        cin >> t1 >> t2;
        a[i+1] = t1;
        b[i+1] = t2;
    }
    vector<ll> ans = FastFourierTransform::multiply(a,b);
    rep(i,1,2*N+1){
        print(ans[i]);
    }
    

}