#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << x << endl
const ll INF = 1e18;
using ld = double;
using P = complex<ld>;
using G = vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const P& a, const P& b) { return a.real()*b.imag() - a.imag()*b.real(); }
ld dot(const P& a, const P& b) { return a.real()*b.real() + a.imag()*b.imag(); }

using C = pair<ld, P>;
#define rad first
#define pnt second

C smallest_enclosing_disc(vector<P> ps){
    auto c3 = [](const P &a, const P &b, const P &c){
        ld A = norm(b - c);
        ld B = norm(c - a);
        ld C = norm(a - b);
        ld S = abs(cross(b - a, c - a));
        P p = (A*(B+C-A)*a + B*(C+A-B)*b + C*(A+B-C)*c) / (4*S*S);
        ld r = abs(p - a);
        return make_pair(r, p);
    };

    auto c2 = [](const P &a, const P &b){
        P c = (a + b) / (ld)2;
        ld r = abs(a - c);
        return make_pair(r, c);
    };

    auto in_circle = [](const P &a, const C &c){
        return norm(a - c.pnt) <= c.rad*c.rad + eps;
    };

    int n = ps.size();
    random_shuffle(ps.begin(), ps.end());
    C c = c2(ps[0], ps[1]);
    for(int i = 2; i < n; ++i){
        if(!in_circle(ps[i], c)){
            c = c2(ps[0], ps[i]);
            for(int j = 1; j < i; ++j){
                if(!in_circle(ps[j], c)){
                    c = c2(ps[j], ps[i]);
                    for(int k = 0; k < j; ++k){
                        if(!in_circle(ps[k], c)){
                            c = c3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}



int n,m;
ld r[111], mb[111];
 
bool used[111];

bool chk(int s){
    vector<int> b;
    rep(i,n)if(!used[i]) b.emplace_back(r[i]);
    vector<ld> a;
    for(int i = s; i < m; ++i) a.emplace_back(mb[i]);
    sort(all(a));
    sort(all(b));
    int last = -1;
    rep(i,a.size()){
        bool found = false;
        for(int j = last+1; j < (int)b.size(); ++j){
            if(a[i] < b[j] + eps){
                found = true;
                last = j;
                break;
            }
        }
        if(!found)return false;
    }
    return true;
}

int main(){
    ll N;
    cin >> N;
    double x[55], y[55];
    rep(i,N) cin >> x[i] >> y[i];
    vector<P> v;
    rep(i,N){
        P c1(x[i], y[i]);
        v.push_back(c1);
    }
    auto res = smallest_enclosing_disc(v);
    double ans = res.first;
    cout << setprecision(12) << ans << endl;
}