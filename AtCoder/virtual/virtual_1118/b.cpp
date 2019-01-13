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
    ll x,y;
    cin >> x >> y;
    if(x >= 0 && y >= 0){
        if(x < y){
            print(y-x);
            return 0;
        }else{
            if(y == 0){
                print(x-y+1);
            }else{
                print(x-y+2);
            }
        }
    }else if(x < 0 && y < 0){
        if(x < y){
            print(y-x);
            return 0;
        }else{
            print(1 + abs(x-y) + 1);
        }
    }else{
        if(x < y){
            if(abs(x) == abs(y)){
                print(1);
            }else if(abs(x) < abs(y)){
                print(x+y+1);
            }else{
                if(y == 0){
                    print(abs(y+x));
                }else{
                    print(abs(y + x) +1);
                }
            }
        }else{
            if(abs(x) == abs(y)){
                print(1);
            }else if(abs(x) < abs(y)){
                print(abs(x+y)+1);
            }else{
                print(x+y+1);
            }
        }
        // if(abs(x) == abs(y)){
        //     print(1);
        // }else if(abs(x) > abs(y)){
        //     print(x+y);
        // }else{
        //     print(x+y+1);
        // }
        // if(x < y){
        //     print(x+y+1);
        //     return 0;
        // }else{
        //     print(abs(x+y)+1);
        //     return 0;
        // }
    }
}
