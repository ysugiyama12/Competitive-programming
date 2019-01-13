#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;
double t[110];
double v[110];
double t_sum[110] = {};
double vmin[50000] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    rep(i,0,N){
        cin >> t[i];
    }
    rep(i,0,N){
        cin >> v[i];
    }
    rep(i,1,N+1){
        t_sum[i] = t_sum[i-1] + t[i-1];
    }
    rep(i,0,t_sum[N] * 2 + 1){
        double vmin_tmp = 1e9;
        double tt = double(i)/2;
        rep(j,0,N){
            if(tt < t_sum[j]){
                vmin_tmp = min(vmin_tmp, v[j] + t_sum[j] - tt);
            }else if(tt >= t_sum[j] && tt <= t_sum[j+1]){
                vmin_tmp = min(vmin_tmp, v[j]);
            }else{
                vmin_tmp = min(vmin_tmp, v[j] + tt - t_sum[j+1]);
            }
        }
        vmin_tmp = min(vmin_tmp, tt);
        vmin_tmp = min(vmin_tmp, t_sum[N] - tt);
        vmin[i] = vmin_tmp;
    }
    double ans = 0;

    rep(i,0,t_sum[N] * 2){
        ans += 0.25 * (vmin[i] + vmin[i+1]);
    }
    cout << setprecision(10) << ans << endl;


}
