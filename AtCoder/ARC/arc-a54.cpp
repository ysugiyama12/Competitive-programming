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
    double L,X,Y,S,D;
    cin >> L >> X >> Y >> S >> D;
    double d1, d2;
    if(S >= D){
        d1 = L - (S-D);
        d2 = S-D;
    }else{
        d1 = D-S;
        d2 = L-(D-S);
    }
    double ans = d1/(X+Y);
    if(X < Y){
        ans = min(ans, d2/(Y-X));
    }
    cout << setprecision(10) << ans << endl;
    ll ans = t + P/pow(2,t/1.5);
    // ans' = 1 + P * pow(2,t/1.5) * log(2) * -1.5
    // 1 = 1.5log(2)Ppow(2,t/1.5)
    // double 
    double ans = 1/(1.5*log(2)*P);
    ans = log2(ans)*1.5;


}
