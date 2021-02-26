#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,C;
    cin >> N >> C;
    int D[31][31] = {0};
    rep(i,0,C){
        rep(j,0,C){
            int tmp;
            cin >> tmp;
            D[i][j] = tmp;
        }
    }
    int c[501][501] = {0};
    rep(i,0,N){
        rep(j,0,N){
            int tmp;
            cin >> tmp;
            c[i][j] = tmp;
        }
    }

    int col[3][31] = {0};
    rep(i,0,N){
        rep(j,0,N){
            col[(i+j)%3][c[i][j]] += 1;
        }
    }
    ll ans = 1<<30;
    rep(i,1,C+1){
        rep(j,1,C+1){
            rep(k,1,C+1){
                if(i != j && j != k && k != i){
                    ll tt = 0;
                    rep(l,1,C+1){
                        tt += col[0][l] * D[l-1][i-1];
                        tt += col[1][l] * D[l-1][j-1];
                        tt += col[2][l] * D[l-1][k-1];
                    }
                    ans = min(ans, tt);
                }
            }
        }
    }
    print(ans);






}
