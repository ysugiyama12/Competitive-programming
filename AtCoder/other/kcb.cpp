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
    int H,W;
    string s[11];
    cin >> H >> W;
    rep(i,0,H){
        cin >> s[i];
    }
    int sx = -1;
    rep(i,0,H){
        rep(j,0,W){
            if(s[i][j] == 's'){
                sx = j;
            }
        }
    }
    rep(i,0, pow(3,H-1)){
        int val = i;
        int s_x = sx;
        vector<int> ope;
        while(val > 0){
            ope.push_back(val % 3);
            val /= 3;
        }
        int n = ope.size();
        rep(j,n,H-1){
            ope.push_back(0);
        }
        bool is_possible = true;
        rep(j,0,H-1){
            if(ope[j] == 0){
                s_x--;
            }else if(ope[j] == 1){
                s_x++;
            }else{

            }
            if(s_x < 0 || s_x >= W) is_possible = false;
            if(s[H-2-j][s_x] == 'x'){
                is_possible = false;
            }
        }
        if(is_possible){
            rep(j,0,H-1){
                if(ope[j] == 0){
                    cout << 'L';
                }else if(ope[j] == 1){
                    cout << 'R';
                }else{
                    cout << 'S';
                }
            }
            cout << endl;
            return 0;
        }
    }
    print("impossible")


}
