#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
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
    int H,W,N;
    cin >> H >> W;
    cin >> N;
    int a[10010];
    rep(i,0,N){
        cin >> a[i];
    }
    int px = 0, py = 0;
    int end_x = W - 1;
    if(H % 2 == 0){
        end_x = 0;
    }
    int a_pos = 0;
    int ans[110][110] = {};
    while(px != end_x || py != H - 1){
        ans[py][px] = a_pos + 1;
        a[a_pos]--;
        if(a[a_pos] == 0){
            a_pos++;
        }
        if(py % 2 == 0 && px == W - 1){
            py++;
        }else if(py % 2 == 1 && px == 0){
            py++;
        }else if(py % 2 == 0){
            px++;
        }else{
            px--;
        }
    }
    ans[H-1][end_x] = N;
    rep(i,0,H){
        rep(j,0,W){
            if(j == W-1){
                cout << ans[i][j];
            }else{
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }

}
