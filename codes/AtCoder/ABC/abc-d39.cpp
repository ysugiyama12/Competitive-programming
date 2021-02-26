#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
#define make_pair mp
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
    ll H,W;
    string S[110];
    cin >> H >> W;
    rep(i,0,H){
        cin >> S[i];
    }
    char hw[110][110];
    rep(i,0,H+2){
        rep(j,0,W+2){
            if(i == 0 || i == H+1){
                hw[i][j] = '#';
            }else if(j == 0 || j == W+1){
                hw[i][j] = '#';
            }else{
                hw[i][j] = S[i-1][j-1];
            }
        }
    }
    int is_check[110][110] = {};
    char ans[110][110];
    rep(i,1,H+1){
        rep(j,1,W+1){
            bool is_black = true;
            rep(k,0,3){
                rep(l,0,3){
                    if(hw[i+k-1][j+l-1] == '.'){
                        is_black = false;
                    }
                }
            }
            if(is_black){
                ans[i-1][j-1] = '#';
                rep(k,0,3){
                    rep(l,0,3){
                        is_check[i+k-1][j+l-1] = 1;
                    }
                }

            }else{
                ans[i-1][j-1] = '.';
            }
        }
    }
    bool is_possible = true;
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == '#' && is_check[i+1][j+1] == 0){
                is_possible = false;
            }
        }
    }
    if(!is_possible){
        print("impossible");
    }else{
        print("possible");
        rep(i,0,H){
            rep(j,0,W){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}
