#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
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
    ll X,Y;
    cin >> X >> Y;
    if(((3 * X - Y) % 8 == 0) && ((3*Y - X) % 8 == 0)){
        if(3*X-Y >= 0 && 3*Y-X >= 0){
            print("Yes");
            return 0;
        }
    }
    print("No");
    // if(X == 0 || Y == 0){
    //     print("No");
    //     return 0;
    // }
    // if(X * 3 == Y || X == Y * 3){
    //     print("Yes");
    //     return 0;
    // }
    // if(X == Y){
    //     if(X % 4 == 0){
    //         print("Yes");
    //     }else{
    //         print("No");
    //     }
    //     return 0;
    // }else if(X < Y){
    //     ll tt = X % 4;
    //     ll v = X - tt;
    //     ll yy = Y - v;
    //     if((yy == 3 * tt) || (tt == 3 * yy)){
    //         print("Yes");
    //         return 0;
    //     }else{
    //         print("No");
    //         return 0;
    //     }
    // }else{
    //     ll tt = Y % 4;
    //     ll v = Y - tt;
    //     ll xx = X - v;
    //     if((xx == 3 * tt) || (xx * 3 == tt)){
    //         print("Yes");
    //         return 0;
    //     }else{
    //         print("No");
    //         return 0;
    //     }

    // }
}
