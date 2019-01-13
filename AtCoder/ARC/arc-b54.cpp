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
    double P;
    cin >> P;
    // f = t + P*pow(2, -t/1.5)
    //f' = 1 - P*pow(2, -t/1.5)*log2/1.5
    double t = 1.5/(log(2)*P);
    t = log2(t)*-1.5;
    if(t < 0){
        cout << setprecision(10) << P << endl;
        return 0;
    }
    double ans = t + P * pow(2,-t/1.5);
    cout << setprecision(10) << ans << endl;
}
