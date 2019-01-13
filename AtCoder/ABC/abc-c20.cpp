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
    int h;
    int w;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
char s[11][11] = {};
ll H,W,T;
ll dist[11][11] = {};
ll pos2num(ll h, ll w){
    return W * h + w;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> T;
    char s[11][11] = {};
    rep(i,0,H){
        rep(j,0,W){
            cin >> s[i][j];
        }
    }
    ll t_right = T;
    ll t_left = 1;
    ll N = H * W;
    ll sh, sw, gh, gw;
    rep(i,0,H){
        rep(j,0,W){
            if(s[i][j] == 'G'){
                gh = i; gw = j;
            }else if(s[i][j] == 'S'){
                sh = i; sw = j;
            }
        }
    }
    while(t_right - t_left > 1){
        ll mid = (t_right + t_left)/2;
        ll d[110][110] = {};
        rep(i,0,N){
            rep(j,0,N){
                if(i == j){
                    d[i][j] = 0;
                }else{
                    d[i][j] = INF;
                }
            }
        }
        ll dh[4] = {1,-1,0,0};
        ll dw[4] = {0,0,1,-1};
        rep(i,0,H){
            rep(j,0,W){
                rep(k,0,4){
                    ll hh = i + dh[k];
                    ll ww = j + dw[k];
                    if(hh >= 0 && hh < H && ww >= 0 && ww < W){
                        ll p1 = pos2num(i,j);
                        ll p2 = pos2num(hh,ww);
                        if(s[hh][ww] == '#'){
                            d[p1][p2] = mid;
                        }else{
                            d[p1][p2] = 1;
                        }
                    }
                }

            }
        }
        rep(k,0,N){
            rep(i,0,N){
                rep(j,0,N){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        ll start = pos2num(sh,sw);
        ll goal = pos2num(gh,gw);
        if(d[start][goal] <= T){
            t_left = mid;
        }else{
            t_right = mid;
        }
    }
    print(t_left);

}
