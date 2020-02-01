#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < n; i++)
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
using ll = long long;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
using lpair = pair<ll, ll>;
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

int main()
{
    //   ll n;
    //   cin >> n;
    //   ll n2 = 1;
    //   while(n2<n) n2*=2;
    //   vector<ll> a(n2,0), b(n2,0);
    //   REP(i,n) cin >> a[i] >> b[i];
    ll N,M;
    cin >> N >> M;
    ll nn = 1;
    while(nn < 1000000) nn *= 2;
    ll a1[200010], b1[200010];
    vector<ll> a(nn,0), b(nn,0);
    rep(i,0,N){
        cin >> a1[i];
        a[a1[i]] = 1;
    }
    rep(i,0,M){
        cin >> b1[i];
        b[b1[i]] = 1;
    }

    vector<ll> ans = FastFourierTransform::multiply(a,b);
    ll val = -1;
    rep(i,2,2000001){
        if(ans[i] >= 2){
            val = i;
            break;
        }
    }
    if(val == -1){
        print(-1);
        return 0;
    }
    vector<lpair> la,lb;
    rep(i,0,N) la.push_back({a1[i],i});
    rep(i,0,M) lb.push_back({b1[i],i});
    sort(la.begin(), la.end(), greater<lpair>());
    sort(lb.begin(), lb.end());
    ll pos = 0;
    vector<lpair> res;
    rep(i,0,N){
        while(1){
            if(pos == M) break;
            if(la[i].first + lb[pos].first == val){
                res.push_back({la[i].second, lb[pos].second});
                pos++;
                break;
            }else if(la[i].first + lb[pos].first < val){
                pos++;
            }else{
                break;
            }
        }
    }
    print(res[0].first, res[0].second, res[1].first, res[1].second);

     
}
