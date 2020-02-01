// 後述の2b.相当のコード
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)

template<class T>
T extgcd(T a, T b, T& x, T& y) {
    for (T u=y=1,v=x=0; a; ) {
        T q = b / a;
        swap(x -= q*u, u);
        swap(y -= q*v, v);
        swap(b -= q*a, a);
    }
    return b;
}

inline long long mod_pow(long long x, long long e, long long mod) {
    long long v = 1LL;
    for ( ; e; e>>=1) {
        if (e & 1) v = (v * x) % mod;
        x = (x * x) % mod;
    }
    return v;
}

inline long long mod_inv(long long a, long long mod) {
    // return mod_pow(a, mod-2, mod); // slower
    long long x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
}

long long _garner(vector<long long>& xs, vector<long long>& mods) {
    int M = xs.size();

    vector<long long> coeffs(M, 1), constants(M, 0);

    for (int i=0; i<M-1; ++i) {
        long long mod_i = mods[i];
        // coffs[i] * v + constants[i] == mr[i].val (mod mr[i].first) を解く
        long long v = (xs[i] - constants[i] + mod_i) % mod_i;
        v = (v * mod_inv(coeffs[i], mod_i)) % mod_i;

        for (int j=i+1; j<M; j++) {
            long long mod_j = mods[j];
            constants[j] = (constants[j] + coeffs[j] * v) % mod_j;
            coeffs[j] = (coeffs[j] * mod_i) % mod_j;
        }
    }

    return constants.back();
}

template<typename T>
inline void bit_reverse(vector<T>& a) {
    int n = a.size();
    int i = 0;
    for (int j=1; j<n-1; ++j) {
        for (int k = n >> 1; k >(i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
}


template<long long mod, long long primitive_root>
class NTT {
public:
    long long get_mod() { return mod; }

    void _ntt(vector<long long>& a, int sign) {
        const int n = a.size();
        assert((n ^ (n&-n)) == 0); //n = 2^k

        const long long g = primitive_root; // g is primitive root of mod

        long long tmp = (mod - 1) * mod_inv(n, mod) % mod; // -1/n
        long long h = mod_pow(g, tmp, mod); // ^n√g
        if (sign == -1) h = mod_inv(h, mod);

        bit_reverse(a);

        for (int m=1; m<n; m<<=1) {
            const int m2 = 2 * m;
            long long _base = mod_pow(h, n/m2, mod);
            long long _w = 1;
            for (int x=0; x<m; ++x) {
                for (int s=x; s<n; s+=m2) {
                    long long u = a[s];
                    long long d = (a[s + m] * _w) % mod;
                    a[s] = (u+d) % mod;
                    a[s+m] = (u-d+mod) % mod;
                }
                _w = (_w * _base) % mod;
            }
        }
    }
    void ntt(vector<long long>& input) {
        _ntt(input, 1);
    }
    void intt(vector<long long>& input) {
        _ntt(input, -1);

        const long long n_inv = mod_inv(input.size(), mod);
        for (auto &x : input) x = (x * n_inv) % mod;
    }

    // 畳み込み演算を行う
    vector<long long> convolution(const vector<long long>& a, const vector<long long>& b){
        int result_size = a.size() + b.size() - 1;
        int n = 1; while (n < result_size) n <<= 1;

        vector<long long> _a = a, _b = b;
        _a.resize(n, 0);
        _b.resize(n, 0);

        ntt(_a);
        ntt(_b);
        for (int i=0; i<n; ++i) _a[i] = (_a[i] * _b[i]) % mod;
        intt(_a);

        _a.resize(result_size);
        return _a;
    }
};


vector<long long> convolution_ntt(vector<long long>& a, vector<long long>& b, long long mod=1224736769LL) {
    for (auto &x : a) x %= mod;
    for (auto &x : b) x %= mod;

    ll maxval = max(a.size(), b.size()) * *max_element(a.begin(), a.end()) * *max_element(b.begin(), b.end());
    if (maxval < 1224736769) {
    	NTT<1224736769, 3> ntt3;
        return ntt3.convolution(a, b);
    }

    NTT<167772161, 3> ntt1;
    NTT<469762049, 3> ntt2;
    NTT<1224736769, 3> ntt3;

    vector<long long> x1 = ntt1.convolution(a, b);
    vector<long long> x2 = ntt2.convolution(a, b);
    vector<long long> x3 = ntt3.convolution(a, b);

    vector<long long> ret(x1.size());
    vector<long long> mods { 167772161, 469762049, 1224736769, mod };
    for (int i=0; i<x1.size(); ++i) {
        vector<long long> xs { x1[i], x2[i], x3[i], 0 };
        ret[i] = _garner(xs, mods);
    }

    return ret;
}
vector<ll> g(2000000+1, 0), h(2000000+1, 0);

ll q[200010];

int main() {
    // int N; cin >> N; // 1-100000

    // vector<ll> g(N+1), h(N+1);

    // g[0] = h[0] = 0;
    // rep(i,N){
    //     int A,B; cin >> A >> B;
    //     g[1+i] = A;
    //     h[1+i] = B;
    // }
    ll p,Q;
    cin >> p >> Q;
    rep(i,Q) cin >> q[i];
    ll N = 2000000;

    g[1] = 0; g[2] = 1; h[1] = 0; h[2] = 1;
    ll M = 1e9+7;
    rep(i,N-2){
        cout << i << "\n";
        g[i+3] = p * g[i+2] % M + g[i+1];
        g[i+3] %= M;
        h[i+3] = g[i+3];
    }

    vector<ll> f = convolution_ntt(g, h, 1000000007LL);
    rep(i,Q){
        cout << f[q[i]] << endl;
    }

    return 0;
}