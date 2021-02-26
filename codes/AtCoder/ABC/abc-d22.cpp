#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll ax[100010], ay[100010], bx[100010], by[100010];
    cin >> N;
    rep(i,0,N){
        cin >> ax[i] >> ay[i];
    }
    rep(i,0,N){
        cin >> bx[i] >> by[i];
    }
    double ma_x = 0.0, ma_y = 0.0, mb_x = 0.0, mb_y = 0.0;
    rep(i,0,N){
        ma_x += (double)ax[i]/N;
        ma_y += (double)ay[i]/N;
        mb_x += (double)bx[i]/N;
        mb_y += (double)by[i]/N;
    }
    double da = 0;
    double db = 0;
    rep(i,0,N){
        da = max(da, sqrt((ma_x - ax[i])*(ma_x - ax[i]) + (ma_y - ay[i])*(ma_y - ay[i])));
        db = max(db, sqrt((mb_x - bx[i])*(mb_x - bx[i]) + (mb_y - by[i])*(mb_y - by[i])));
    }
    double ans = db/da;
    cout << setprecision(10) << ans << endl;
    // if(N > 3010) return 0;
    // double da = LONG_MAX;
    // double db = LONG_MAX;
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(i != j){
    //             da = min(da, sqrt(pow(ax[i] - ax[j],2) + pow(ay[i] - ay[j],2)));
    //             db = min(db, sqrt(pow(bx[i] - bx[j],2) + pow(by[i] - by[j],2)));
    //         }
    //     }
    // }
    // double ans = db / da;
    // cout << setprecision(10) << ans << endl;

}
