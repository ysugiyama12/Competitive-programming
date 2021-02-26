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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    cin >> H >> W;
    ll c[11][11] = {};
    rep(i,0,10){
        rep(j,0,10){
            cin >> c[i][j];
        }
    }
    ll A[210][210] = {};
    rep(i,0,H){
        rep(j,0,W){
            cin >> A[i][j];
        }
    }
    rep(k,0,10){
        rep(i,0,10){
            rep(j,0,10){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    ll ans = 0;
    rep(i,0,H){
        rep(j,0,W){
            if(A[i][j] >= 0){
                ans += c[A[i][j]][1];
            }
        }
    }
    print(ans);


}
