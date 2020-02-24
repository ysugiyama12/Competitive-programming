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
#define EPS (1e-30)
#define EQ(a,b) (abs((a) - (b)) < EPS)
typedef complex<double> P;

double dot(P a, P b){ //内積
    return (a.real() * b.real() + a.imag() * b.imag());
}
double norm(P a){
  return a.real() * a.real() +a.imag() *a.imag();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << 1e-330 << endl;
    ll N;
    cin >> N;
    double x[100010], y[100010];
    rep(i,0,N) cin >> x[i] >> y[i];
    if(N % 2 == 1){
        print("NO");
        return 0;
    }
    vector<double> angle;
    vector<P> v2;
    rep(i,0,N){
        P p1(x[i], y[i]);
        v2.push_back(p1);
    }

    rep(i,0,N){
        double v = 0.0;
        // double v = atan2(v2[i] - v2[i-1], v2[i+1] - v2[i]);
        if(i == 0){
            v = dot(v2[0] - v2[N-1], v2[1]-v2[0]);
            v /= norm(v2[0] - v2[N-1]) * norm(v2[1] - v2[0]);

        }else if(i == N-1){
            v = dot(v2[N-1] - v2[N-2], v2[0]-v2[N-1]);
            v /= norm(v2[N-1] - v2[N-2]) * norm(v2[0] - v2[N-1]);

        }else{
            v = dot(v2[i] - v2[i-1], v2[i+1]-v2[i]);
            v /= norm(v2[i] - v2[i-1]) * norm(v2[i+1] - v2[i]);

        }
        angle.push_back(v);
    }
    bool ok = true;
    rep(i,0,N/2){
        if(not EQ(angle[i], angle[i+N/2])) ok = false;
    }
    if(ok){
        print("YES");
    }else{
        print("NO");
    }


    

}