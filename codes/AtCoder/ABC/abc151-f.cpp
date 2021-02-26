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
#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)

using P = complex<double>;
double dot(P a, P b){ //内積
    return (a.X * b.X + a.Y * b.Y);
}

double cross(P a, P b){ //外積
    return (a.X * b.Y - a.Y * b.X);
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
  return a.X * a.X +a.Y *a.Y;
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
  return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 &&
      ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    P pos[55];
    rep(i,0,N){
        double x,y;
        cin >> x >> y;
        P p1(x,y);
        pos[i] = p1;
    }
    // 2点の時
    double ans = 1e9;
    rep(i,0,N){
        rep(j,i+1,N){
            P c = (pos[i] + pos[j]) / 2.0;
            double r = abs(pos[i] - pos[j]) / 2.0;
            bool ok = true;
            rep(k,0,N){
                if(k == i || k == j) continue;
                double d = abs(c - pos[k]);
                if(d > r + EPS){
                    ok = false;
                }
            }
            if(ok){
                ans = min(ans, r);
            }
        }
    }

    // 3点の時
    rep(i,0,N){
        rep(j,i+1,N){
            rep(k,j+1,N){
                // if(is_para(pos[i], pos[j], pos[j], pos[k])) continue;
                P c1 = (pos[i] + pos[j]) / 2.0;
                P a1 = pos[i] - pos[j];
                P a2 = pos[i] - pos[k];
                P e1,e2;
                if(EQ(a1.Y, 0.0)){
                    e1 = P(0,1.0);
                }else{
                    e1 = P(1, -a1.X / a1.Y);
                }
                P c2 = (pos[i] + pos[k]) / 2.0;
                if(EQ(a2.Y, 0.0)){
                    e2 = P(0,1.0);
                }else{
                    e2 = P(1.0, -a2.X / a2.Y);
                }

                P center = intersect_pos(c1, c1+e1, c2, c2+e2);
                double r = abs(center - pos[i]);

                bool ok = true;
                rep(k2,0,N){
                    if(k2 == i || k2 == j || k2 == k) continue;
                    double d = abs(center - pos[k2]);
                    if(d > r + EPS){
                        ok = false;
                    }
                }
                if(ok){
                    ans = min(ans, r);
                }
            }
        }
    }
    cout << setprecision(10) << ans << endl;

}