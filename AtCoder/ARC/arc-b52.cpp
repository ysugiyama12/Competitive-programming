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
    ll N,Q;
    double X[110], R[110], H[110];
    double A[100010], B[100010];
    cin >> N >> Q;
    rep(i,0,N){
        cin >> X[i] >> R[i] >> H[i];
    }
    rep(i,0,Q){
        cin >> A[i] >> B[i];
    }
    rep(q,0,Q){
        double ans = 0.0;
        rep(n,0,N){
            if(X[n] > B[q] || X[n] + H[n] < A[q]) continue;
            double v1 = max(A[q], X[n]);
            double v2 = min(B[q], X[n] + H[n]);
            double r = (X[n] + H[n] - v1) * R[n] / H[n];
            double V = M_PI * r * r * (X[n] + H[n] - v1) / 3;
            double r2 = (X[n] + H[n] - v2) * R[n] / H[n];
            double Vd = M_PI * r2 * r2 * (X[n] + H[n] - v2) / 3;
            ans += V - Vd;
        }
        cout << setprecision(16) << ans << endl;
    }

}
