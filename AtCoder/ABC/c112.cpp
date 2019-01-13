#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
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
    int N;
    ll x[110], y[110], h[110];
    cin >> N;
    rep(i,0,N){
        cin >> x[i] >> y[i] >> h[i];
    }
    rep(i,0,101){
        rep(j,0,101){
            ll cx = i;
            ll cy = j;
            bool is_ok = true;
            ll val = -1;
            ll dist_min = 1e9;
            rep(k,0,N){
                ll val_tmp = 0;
                if(h[k] != 0){
                    val_tmp = h[k] + abs(x[k] - cx) + abs(y[k] - cy);
                    if(val == -1){
                        val = val_tmp;
                    }else{
                        if(val != val_tmp){
                            is_ok = false;
                        }
                    }
                }else{
                    ll max_h = abs(x[k] - cx) + abs(y[k] - cy);
                    dist_min = min(dist_min, max_h);
                }
            }
            //rep(k,1,N){
            //    ll val_tmp = h[k] + abs(x[k] - cx) + abs(y[k] - cy);
            //    if(val != val_tmp){
            //        is_ok = false;
            //    }
            //}
            if(dist_min != 1e9 && val > dist_min){
                is_ok = false;
            }
            if(is_ok && val > 0){
                cout << cx << " " << cy << " " << val << endl;
                return 0;
            }
        }
    }

}
