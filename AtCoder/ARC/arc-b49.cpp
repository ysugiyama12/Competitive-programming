#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    double x[1010], y[1010], c[1010];
    cin >> N;
    rep(i,0,N){
        cin >> x[i] >> y[i] >> c[i];
    }
    double rv = INF, lv = 0;
    ll ctr = 0;
    while(ctr < 256){
        double mid = (rv + lv) / 2;
        bool ok = false;
        double x_left = -INF, x_right = INF, y_left = -INF, y_right = INF;
        rep(i,0,N){
            double v = mid / c[i];
            x_left = max(x_left, x[i] - v);
            x_right = min(x_right, x[i] + v);
            y_left = max(y_left, y[i] - v);
            y_right = min(y_right, y[i] + v);
        }
        if(x_left <= x_right && y_left <= y_right){
            ok = true;
        }
        if(ok){
            rv = mid;
        }else{
            lv = mid;
        }
        ctr++;
    }
    cout << setprecision(14) << rv << endl;
}
