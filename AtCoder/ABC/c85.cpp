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
    int N,Y;
    cin >> N >> Y;
    rep(x,0,N+1){
        rep(y,0,N+1){
            if(x+y > N) continue;
            int z = N - x - y;
            if(x * 10000 + y * 5000 + z * 1000 == Y){
                cout << x << " " << y << " " << z << endl;
                return 0;
            }

        }
    }
    print("-1 -1 -1");
}
