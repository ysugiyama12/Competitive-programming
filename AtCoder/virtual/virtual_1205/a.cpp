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
double t[110] = {}, v[110] = {};
double min_val[50000];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    double t_sum = 0;
    rep(i,1,N+1){
        cin >> t[i];
        t_sum += t[i];
    }
    rep(i,1,N+1){
        cin >> v[i];
    }
    t[N+1] = 0;
    v[N+1] = 0;
    double ans = 0;
    // printa(t,N+2);
    // printa(v,N+2);
    rep(i,0,2 * t_sum + 1){
        double now_time = 0.5 * i;
        double val = INF;
        double tt = 0;
        rep(j,0,N+2){
            // print(tt);
            if(tt > now_time){
                val = min(val, v[j] + tt - now_time);
            }else if(tt + t[j] < now_time){
                val = min(val, v[j] + now_time - (tt + t[j]));
                // print(val);
            }else{
                val = min(val, v[j]);
            }
            tt += t[j];
            // print(tt);
        }
        // print(val);
        min_val[i] = max(val,0.0);
    }
    rep(i,1,2*t_sum + 1){
        ans += 0.25 * (min_val[i-1] + min_val[i]);
    }
    cout << setprecision(10) << ans << endl;


}
