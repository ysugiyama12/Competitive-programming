#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double X,Y;
    ll N;
    double x[11], y[11];
    cin >> X >> Y;
    cin >> N;
    rep(i,0,N){
        cin >> x[i] >> y[i];
        x[i] -= X;
        y[i] -= Y;
    }
    double ans = INF;
    rep(i,0,N){
        double x1 = x[i], x2 = x[(i+1)%N], y1 = y[i], y2 = y[(i+1)%N];
        double dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        double height = abs(x1*y2 - x2*y1)/ dist;
        double d1 = sqrt(x1*x1 + y1*y1);
        double d2 = sqrt(x2*x2 + y2*y2);
        double cos1 = (x1*(x1-x2) + y1*(y1-y2)) / (d1*dist);
        double cos2 = (x2*(x2-x1) + y2*(y2-y1)) / (d2*dist);
        if(cos1 * cos2 > 0){
            ans = min(ans, height);
        }else{
            ans = min(ans, min(d1,d2));
        }
    }
    cout << setprecision(10) << ans << endl;

}
