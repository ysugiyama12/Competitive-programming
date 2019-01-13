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
    int N;
    int F[110][11];
    int P[110][11];
    cin >> N;
    rep(i,0,N){
        rep(j,0,10){
            cin >> F[i][j];
        }
    }
    rep(i,0,N){
        rep(j,0,11){
            cin >> P[i][j];
        }
    }
    ll ans = -1e10;
    rep(i,0,(1 << 10)){
        if(i == 0) continue;
        ll ans_tmp = 0;
        rep(j,0,N){
            int cnt = 0;
            rep(k,0,10){
                if(i >> k & 1){
                    cnt += F[j][k];
                }
            }
            ans_tmp += P[j][cnt];
        }
        ans = max(ans, ans_tmp);
    }
    print(ans);

}
