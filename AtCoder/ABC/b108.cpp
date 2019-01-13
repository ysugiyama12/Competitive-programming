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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x2 -= x1;
    y2 -= y1;
    int dx = x2;
    int dy = y2;
    int ddx = -1 * dy;
    int ddy = dx;
    int x4 = ddx + x1;
    int y4 = ddy + y1;
    int x3 = x4 + x2;
    int y3 = y4 + y2;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;


    // if(x1 == x2){
    //     int y = abs(y1 - y2);
    //     if(y1 > y2){
    //         cout << x1 + y << " " << y2 << " " << x1 + y << " " << y1 << endl;
    //     }else{
    //         cout << x1 - y << " " << y2 << " " << x1 - y << " " << y1 << endl;
    //     }
    // }else{
    //     int x = abs(x1 - x2);
    //     if(x1 > x2){
    //         cout << x2 << " " << y2 - x << " " << x1 << " " << y2 - x << endl; 
    //     }else{
    //         cout << x2 << " " << y2 + x << " " << x1 << " " << y2 + x << endl; 
    //     }
    // }

}
