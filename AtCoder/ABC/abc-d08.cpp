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
    ll W,H,N;
    cin >> W >> H >> N;
    ll X[31], Y[31];
    rep(i,0,N){
        cin >> X[i] >> Y[i];
    }
    if(N > 8) return 0;
    vector<ll> v(N);
    iota(v.begin(), v.end(), 0);
    ll ans = 0;
    do{
        // printa(v,N);
        ll gold[100][100] = {};
        rep(i,1,H+1){
            rep(j,1,W+1){
                gold[j][i] = 1;
            }
        }
        // printa2(gold,H+2,W+2);
        ll tt = 0;
        rep(i,0,N){
            ll px = X[v[i]];
            ll py = Y[v[i]];
            // print2(px,py);
            gold[px][py]--;
            tt += 1;
            for(int y = py+1; y <= H; y++){
                if(gold[px][y] == 1){
                    tt++;
                    gold[px][y] = 0;
                }else{
                    break;
                }
            }
            for(int y = py-1; y >= 1; y--){
                if(gold[px][y] == 1){
                    tt++;
                    gold[px][y] = 0;
                }else{
                    break;
                }
            }
            for(int x = px+1; x <= W; x++){
                if(gold[x][py] == 1){
                    tt++;
                    gold[x][py] = 0;
                }else{
                    break;
                }
            }
            for(int x = px-1; x >= 1; x--){
                if(gold[x][py] == 1){
                    tt++;
                    gold[x][py] = 0;
                }else{
                    break;
                }
            }
            // printa2(gold,H+2,W+2);
            // print(tt);
            // print("");

        }
        ans = max(ans,tt);

    }while(next_permutation(v.begin(), v.end()));
    print(ans);
}
