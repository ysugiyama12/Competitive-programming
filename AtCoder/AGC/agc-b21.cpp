#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    double x[110], y[110];
    cin >> N;
    rep(i,0,N) cin >> x[i] >> y[i];
    rep(i,0,N){
        vector<double> angle;
        rep(j,0,N){
            if(i == j) continue;
            if(y[i] == y[j]){
                angle.push_back(INF);
            }else{
                double v = -1 * (x[j] - x[i]) / (y[j] - y[i]);
                angle.push_back(v);
            }
        }
        sort(angle.begin(), angle.end());
        double angle_max = angle[angle.size()-1];
        double angle_min = angle[0];
        double tans = (angle_max - angle_min) / (1 + angle_max * angle_min);
        double ang = atan(tans);
        double p = (M_PI - ang) / (2*M_PI);
        printa(angle, angle.size());
        print(p);

        // printa(angle, angle.size());
    }
}
