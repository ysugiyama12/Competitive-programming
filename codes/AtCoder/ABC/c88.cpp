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

    int c[3][3] = {0};
    rep(i,0,3){
        rep(j,0,3){
            int tmp;
            cin >> tmp;
            c[i][j] = tmp;
        }
    }
    bool flg = false;
    rep(i,0,c[0][0]+1){
        int a1 = i;
        int b1 = c[0][0] - i;
        int b2 = c[0][1] - a1;
        int b3 = c[0][2] - a1;
        int a2 = c[1][0] - b1;
        int a3 = c[2][0] - b1;
        if(a2 + b2 == c[1][1] && a2+b3 == c[1][2] && a3+b2 == c[2][1] && a3+b3 == c[2][2]){
            flg = true;
        }


    }
    if(flg){
        print("Yes");
    }else{
        print("No");
    }
}
