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

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    // Contracts: 0 <= r0 < m0
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
        // r2 % m0 = r0
        // r2 % m1 = r1
        // -> (r0 + x*m0) % m1 = r1
        // -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)
        // -> x = (r1 - r0) / g * inv(u0) (mod u1)

        // im = inv(u0) (mod u1) (0 <= im < u1)
        long long g, im;
        std::tie(g, im) = inv_gcd(m0, m1);

        long long u1 = (m1 / g);
        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
        if ((r1 - r0) % g) return {0, 0};

        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
        long long x = (r1 - r0) / g % u1 * im % u1;

        // |r0| + |m0 * x|
        // < m0 + m0 * (u1 - 1)
        // = m0 + m0 * m1 / g - m0
        // = lcm(m0, m1)
        r0 += x * m0;
        m0 *= u1;  // -> lcm(m0, m1)
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}


void solve(){
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}