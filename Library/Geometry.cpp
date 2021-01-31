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
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

// Geometry Library
// P: point, L: line, S: segment
const double EPS = 1e-8;

using P = complex<double>;
using G = vector<P>;

namespace std {
    bool operator < (const P& a, const P& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}


double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}

struct L : public vector<P> {
    L(const P &a, const P &b) {
        push_back(a); push_back(b);
    }
};


struct C { // 円
    P p; double r;
    C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0; // a--c--b
}

bool intersectLL(const L &l, const L &m) {
    return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
            abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}

bool intersectLS(const L &l, const L &s) {
    return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
            cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}

bool intersectLP(const L &l, const P &p) {
    return abs(cross(l[1]-p, l[0]-p)) < EPS;
}

bool intersectSS(const L &s, const L &t) {
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
            ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

bool intersectSP(const L &s, const P &p) {
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

P projection(const L &l, const P &p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}

P reflection(const L &l, const P &p) {
    return p + 2.0 * (projection(l, p) - p);
}

double distanceLP(const L &l, const P &p) {
    return abs(p - projection(l, p));
}

double distanceLL(const L &l, const L &m) {
    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}

double distanceLS(const L &l, const L &s) {
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}

double distanceSP(const L &s, const P &p) {
    const P r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}

double distanceSS(const L &s, const L &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
                min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

P crosspoint(const L &l, const L &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
}

bool is_orth(L l1, L l2){
    return abs(dot(l1[1] - l1[0], l2[1] - l2[0])) < EPS;
}

bool is_para(L l1, L l2){
    return abs(cross(l1[1] - l1[0], l2[1] - l2[0])) < EPS;
}

double closest_pair(vector<P> ps) {
    if(ps.size() <= 1) throw (0);
    sort(begin(ps), end(ps));

    auto compare_y = [&](const P &a, const P &b) {
        return imag(a) < imag(b);
    };
    vector< P > beet(ps.size());
    const double INF = 1e18;

    function< double(int, int) > rec = [&](int left, int right) {
        if(right - left <= 1) return INF;
        int mid = (left + right) >> 1;
        auto x = real(ps[mid]);
        auto ret = min(rec(left, mid), rec(mid, right));
        inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);
        int ptr = 0;
        for(int i = left; i < right; i++) {
            if(abs(real(ps[i]) - x) >= ret) continue;
            for(int j = 0; j < ptr; j++) {
                auto luz = ps[i] - beet[ptr - j - 1];
                if(imag(luz) >= ret) break;
                ret = min(ret, abs(luz));
            }
            beet[ptr++] = ps[i];
        }
        return ret;
    };
    return rec(0, (int) ps.size());
}

void solve(){
    ll N;
    cin >> N;
    vector<P> v(N);
    L l1(v[0], v[1]);
    rep(i,0,N){
        double x,y; 
        cin >> x >> y;
        v[i] = {x,y};
    }
    auto res = closest_pair(v);
    print(res);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    solve();
}