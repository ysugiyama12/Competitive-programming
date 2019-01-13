#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    cin >> H >> W;
    string S[101];
    rep(i,0,H){
        cin >> S[i];
    }
    int flg_h[101] = {};
    int flg_w[101] = {};
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == '#'){
                flg_w[j] = 1;
                flg_h[i] = 1;
            }
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            if(flg_w[j] == 1 && flg_h[i] == 1){
                cout << S[i][j];
            }
        }
        if(flg_h[i] == 1){
            cout << endl;
        }
    }
}
