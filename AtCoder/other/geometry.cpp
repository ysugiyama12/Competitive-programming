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

// geometry library
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
typedef complex<double> P;
double dot(P a, P b){ //内積
    return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(P a, P b){ //外積
    return (a.real() * b.imag() - a.imag() * b.real());
}

bool is_orth(P a1, P a2, P b1, P b2){ //垂直か
    return EQ(dot(a1 - a2, b1 - b2), 0.0);
}

bool is_para(P a1, P a2, P b1, P b2){ //平行か
    return EQ(cross(a1 - a2, b1 - b2), 0.0);
}

bool is_online(P a, P b, P c){ //cが線分上か
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS);
}

bool distance_lp(P a, P b, P c){ //直線abと点cの距離
    return abs(cross(b-a, c-a)) / abs(b-a);
}

double norm(P a){
  return a.real() * a.real() +a.imag() *a.imag();
}

ll ccw(P p0,P p1,P p2){
  P a = p1-p0;
  P b = p2-p0;
  if(cross(a,b) > EPS) return 1;
  if(cross(a,b) < -EPS) return -1;
  if(dot(a,b) < -EPS) return 2;
  if(abs(a) < abs(b)) return -2;
  return 0;
}

bool is_intersect(P p1, P p2, P p3, P p4){
    return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 && ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
}

P intersect_pos(P a1, P a2, P b1, P b2){ //直線同士の交点
    P a = a2 - a1;
    P b = b2 - b1;
    return a1 + a * cross(b, b1 - a1) / cross(b, a);
}

double getDistanceLP(P a1, P a2, P b){
    return abs(cross(a2-a1, b-a1) / abs(a2 - a1));
}

double getDistanceSP(P a1, P a2, P b){
    if(dot(a2 - a1, b - a1) < EPS) return abs(b - a1);
    if(dot(a1 - a2, b - a2) < EPS) return abs(b - a2);
    return getDistanceLP(a1, a2, b);
}
double getDistance(P a1, P a2, P b1, P b2){
    if(is_intersect(a1, a2, b1, b2)) return 0.0;
    double v1 = min(getDistanceSP(a1, a2, b1), getDistanceSP(a1, a2, b2));
    double v2 = min(getDistanceSP(b1, b2, a1), getDistanceSP(b1, b2, a2));
    return min(v1,v2);
}

bool isconvex(vector<P> ps) {
    ll n = ps.size();
    rep(i,0,n){
        if (ccw(ps[(i-1+n)%n], ps[i], ps[(i+1)%n]) > 0) return false;
    }
    return true;
}

vector<P> convex_hull(vector<P> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end(), [](P p1, P p2){
        if(p1.real() == p2.real()) {
            return p1.imag() < p2.imag();
        }
        return p1.real() < p2.real();
    });
    
    vector<P> ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]){
        // while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) < 0){
        while (k >= 2 && cross( ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < 0){
            k--;
        }
    }

    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]){
        // while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) < 0){
        while (k >= t && cross( ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < 0){
            k--;
        }
    }
    ch.resize(k-1);
    return ch;
}

double angle(P p1, P p2, P p3){ // <p1p2p3
    double cosine = dot(p2 - p1, p3 - p2);
    cosine /= sqrt(norm(p2 - p1) * norm(p3 - p2));
    return acos(cosine);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[100010], y[100010];
    vector<P> ps;
    rep(i,0,N){
        cin >> x[i] >> y[i];
        P p1(x[i], y[i]);
        ps.push_back(p1);
    }
    vector<P> convex = convex_hull(ps);
    ll m = convex.size();
    print(m);
    vector<P> tmp = convex;

    sort(tmp.begin(), tmp.end(), [](P p1, P p2){
        if(p1.imag() == p2.imag()){
            return p1.real() < p2.real();
        }
        return p1.imag() < p2.imag();
    });
    ll start = -1;
    rep(i,0,m){
        if(EQ(convex[i], tmp[0])){
            start = i;
            break;
        }
    }
    rep(i,0,m){
        ll idx = (i+start)%m;
        print(convex[idx].real(), convex[idx].imag());
    }
}