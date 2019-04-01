#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double x[3], y[3];
    rep(i,0,3) cin >> x[i] >> y[i];
    x[1] -= x[0]; x[2] -= x[0];
    y[1] -= y[0]; y[2] -= y[0];
    x[0] = 0; y[0] = 0;
    double S = abs(x[1]*y[2] - x[2]*y[1]) / 2;
    double a = sqrt(x[1]*x[1] + y[1]*y[1]);
    double b = sqrt(x[2]*x[2] + y[2]*y[2]);
    double c = sqrt((x[1]-x[2])*(x[1]-x[2]) + (y[1]-y[2]) * (y[1]-y[2]));
    double r = 2 * S / (a+b+c);
    double cc = max(max(a,b), c);
    double ans = cc/(2+cc/r);
    cout << setprecision(10) << ans << endl;
    
}