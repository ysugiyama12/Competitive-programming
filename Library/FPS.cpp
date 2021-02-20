/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};
template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;
template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;
template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;
template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }
    static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};
using mint = static_modint<1000000007>;

template<typename T>
struct FormalPowerSeries {
    using Poly = vector<T>;
    using Conv = function<Poly(Poly, Poly)>;
    Conv conv;
    FormalPowerSeries(Conv conv) :conv(conv) {}

    Poly pre(const Poly& as, int deg) {
        return Poly(as.begin(), as.begin() + min((int)as.size(), deg));
    }

    Poly add(Poly as, Poly bs) {
        int sz = max(as.size(), bs.size());
        Poly cs(sz, T(0));
        for (int i = 0; i < (int)as.size(); i++) cs[i] += as[i];
        for (int i = 0; i < (int)bs.size(); i++) cs[i] += bs[i];
        return cs;
    }

    Poly sub(Poly as, Poly bs) {
        int sz = max(as.size(), bs.size());
        Poly cs(sz, T(0));
        for (int i = 0; i < (int)as.size(); i++) cs[i] += as[i];
        for (int i = 0; i < (int)bs.size(); i++) cs[i] -= bs[i];
        return cs;
    }

    Poly mul(Poly as, Poly bs) {
        return conv(as, bs);
    }

    Poly mul(Poly as, T k) {
        for (auto& a : as) a *= k;
        return as;
    }

    // F(0) must not be 0
    Poly inv(Poly as, int deg) {
        assert(as[0] != T(0));
        Poly rs({ T(1) / as[0] });
        for (int i = 1; i < deg; i <<= 1)
            rs = pre(sub(add(rs, rs), mul(mul(rs, rs), pre(as, i << 1))), i << 1);
        return rs;
    }

    // not zero
    Poly div(Poly as, Poly bs) {
        while (as.back() == T(0)) as.pop_back();
        while (bs.back() == T(0)) bs.pop_back();
        if (bs.size() > as.size()) return Poly();
        reverse(as.begin(), as.end());
        reverse(bs.begin(), bs.end());
        int need = as.size() - bs.size() + 1;
        Poly ds = pre(mul(as, inv(bs, need)), need);
        reverse(ds.begin(), ds.end());
        return ds;
    }

    // F(0) must be 1
    Poly sqrt(Poly as, int deg) {
        assert(as[0] == T(1));
        T inv2 = T(1) / T(2);
        Poly ss({ T(1) });
        for (int i = 1; i < deg; i <<= 1) {
            ss = pre(add(ss, mul(pre(as, i << 1), inv(ss, i << 1))), i << 1);
            for (T& x : ss) x *= inv2;
        }
        return ss;
    }

    Poly diff(Poly as) {
        int n = as.size();
        Poly res(n - 1);
        for (int i = 1; i < n; i++) res[i - 1] = as[i] * T(i);
        return res;
    }

    Poly integral(Poly as) {
        int n = as.size();
        Poly res(n + 1);
        res[0] = T(0);
        for (int i = 0; i < n; i++) res[i + 1] = as[i] / T(i + 1);
        return res;
    }

    // F(0) must be 1
    Poly log(Poly as, int deg) {
        return pre(integral(mul(diff(as), inv(as, deg))), deg);
    }

    // F(0) must be 0
    Poly exp(Poly as, int deg) {
        Poly f({ T(1) });
        as[0] += T(1);
        for (int i = 1; i < deg; i <<= 1)
            f = pre(mul(f, sub(pre(as, i << 1), log(f, i << 1))), i << 1);
        return f;
    }

    Poly partition(int n) {
        Poly rs(n + 1);
        rs[0] = T(1);
        for (int k = 1; k <= n; k++) {
            if (1LL * k * (3 * k + 1) / 2 <= n) rs[k * (3 * k + 1) / 2] += T(k % 2 ? -1LL : 1LL);
            if (1LL * k * (3 * k - 1) / 2 <= n) rs[k * (3 * k - 1) / 2] += T(k % 2 ? -1LL : 1LL);
        }
        return inv(rs, n + 1);
    }
};


#define sz(c) ((int)(c).size())
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
struct MathsNTTModAny {
    template<int mod, int primitive_root>
    class NTT {
    public:
        int get_mod() const { return mod; }
        void _ntt(vector<ll>& a, int sign) {
            const int n = sz(a);
            assert((n ^ (n & -n)) == 0); //n = 2^k

            const int g = 3; //g is primitive root of mod
            int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
            if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod

            //bit reverse
            int i = 0;
            for (int j = 1; j < n - 1; ++j) {
                for (int k = n >> 1; k > (i ^= k); k >>= 1);
                if (j < i) swap(a[i], a[j]);
            }

            for (int m = 1; m < n; m *= 2) {
                const int m2 = 2 * m;
                const ll base = mod_pow(h, n / m2, mod);
                ll w = 1;
                rep(x,0,m) {
                    for (int s = x; s < n; s += m2) {
                        ll u = a[s];
                        ll d = a[s + m] * w % mod;
                        a[s] = u + d;
                        if (a[s] >= mod) a[s] -= mod;
                        a[s + m] = u - d;
                        if (a[s + m] < 0) a[s + m] += mod;
                    }
                    w = w * base % mod;
                }
            }

            for (auto& x : a) if (x < 0) x += mod;
        }
        void ntt(vector<ll>& input) {
            _ntt(input, 1);
        }
        void intt(vector<ll>& input) {
            _ntt(input, -1);
            const int n_inv = mod_inv(sz(input), mod);
            for (auto& x : input) x = x * n_inv % mod;
        }

        vector<ll> convolution(const vector<ll>& a, const vector<ll>& b) {
            int ntt_size = 1;
            while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

            vector<ll> _a = a, _b = b;
            _a.resize(ntt_size); _b.resize(ntt_size);

            ntt(_a);
            ntt(_b);

            rep(i,0,ntt_size) {
                (_a[i] *= _b[i]) %= mod;
            }

            intt(_a);
            return _a;
        }
    };

    ll garner(vector<pair<int, int>> mr, int mod) {
        mr.emplace_back(mod, 0);

        vector<ll> coffs(sz(mr), 1);
        vector<ll> constants(sz(mr), 0);
        rep(i,0,sz(mr)-1) {
            // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first)
            ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
            if (v < 0) v += mr[i].first;

            for (int j = i + 1; j < sz(mr); j++) {
                (constants[j] += coffs[j] * v) %= mr[j].first;
                (coffs[j] *= mr[i].first) %= mr[j].first;
            }
        }

        return constants[sz(mr) - 1];
    }

    typedef NTT<167772161, 3> NTT_1;
    typedef NTT<469762049, 3> NTT_2;
    typedef NTT<1224736769, 3> NTT_3;

    vector<ll> solve(vector<ll> a, vector<ll> b, int mod = 1000000007) {
        for (auto& x : a) x %= mod;
        for (auto& x : b) x %= mod;

        NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
        assert(ntt1.get_mod() < ntt2.get_mod() && ntt2.get_mod() < ntt3.get_mod());
        auto x = ntt1.convolution(a, b);
        auto y = ntt2.convolution(a, b);
        auto z = ntt3.convolution(a, b);

        const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
        const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
        const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
        const ll m12_mod = m1 * m2 % mod;
        vector<ll> ret(sz(x));
        rep(i,0,sz(x)) {
            ll v1 = (y[i] - x[i]) * m1_inv_m2 % m2;
            if (v1 < 0) v1 += m2;
            ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
            if (v2 < 0) v2 += m3;
            ll constants3 = (x[i] + m1 * v1 + m12_mod * v2) % mod;
            if (constants3 < 0) constants3 += mod;
            ret[i] = constants3;
        }

        return ret;
    }

    vector<int> solve(vector<int> a, vector<int> b, int mod = 1000000007) {
        vector<ll> x(a.begin() ,a.end());
        vector<ll> y(b.begin(), b.end());

        auto z = solve(x, y, mod);
        vector<int> res;
        for(auto &aa: z) res.push_back(aa % mod);

        return res;
    }

    vector<mint> solve(vector<mint> a, vector<mint> b, int mod = 1000000007) {
        int n = a.size();
        vector<ll> x(n);
        rep(i, 0, n) x[i] = a[i].val();
        n = b.size();
        vector<ll> y(n);
        rep(i, 0, n) y[i] = b[i].val();

        auto z = solve(x, y, mod);
        vector<int> res;
        for(auto &aa: z) res.push_back(aa % mod);

        vector<mint> res2;
        for(auto &x: res) res2.push_back(x);

        return res2;
    }
};

void solve(){
    ll K,N;
    cin >> K >> N;
    vll x(N);
    rep(i,0,N) cin >> x[i];
    FormalPowerSeries<mint> FPS([&](auto a, auto b) {
        MathsNTTModAny ntt;
        return ntt.solve(a, b);
    });
    vector<mint> f(K+1, 0);
    f[0] = 1;
    rep(i,0,N) f[x[i]] = -1;
    f = FPS.inv(f, K+1);
    print(f[K].val());
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}