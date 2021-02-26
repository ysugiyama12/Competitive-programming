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
typedef struct {
    double x;
    double y;
    double arg;
} P;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    double x[110], y[110];
    rep(i,0,N) cin >> x[i] >> y[i];
    vector<P> vp;
    rep(i,0,N){
        double tans = atan2(y[i], x[i]);
        vp.push_back((P) {x[i], y[i], tans});
    }
    sort(vp.begin(), vp.end(), [](P p1, P p2){
        return p1.arg < p2.arg;
    });
    double ans = 0.0;
    rep(i,0,N){
        rep(j,1,N+1){
            double x_sum = 0.0, y_sum = 0.0;
            rep(k,i,i+j){
                ll p = k % N;
                x_sum += vp[p].x;
                y_sum += vp[p].y;
            }
            ans = max(ans, sqrt(x_sum*x_sum + y_sum * y_sum));
        }

    }
    cout << setprecision(12) << ans << endl;

    

}