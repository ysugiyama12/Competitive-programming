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
    ll N;
    double a[4000], b[4000], c[4000], d[4000], e[4000];
    cin >> N;
    rep(i,0,N){
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }
    double ans = 0.0;
    rep(i,0,N){
        ans = max(ans, a[i]+b[i]+c[i]+d[i]+e[i]*110/900);
    }
    cout << setprecision(10) << ans << endl;
}
