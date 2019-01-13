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
    int N,M;
    cin >> N >> M;
    int x,y;
    int x_inv, y_inv;
    int total = 0;
    rep(i,1,N+1){
        rep(j,1,M+1){
            // if(i != 13 || j != 13) continue;
            // print(i);
            // print(j);
            // print("");
            x = i;
            y = j;
            int count = 0;
            while(1){
                if(x == 0 || y == 0) break;
                // print(x);
                // print(y);
                string x_s = to_string(x);
                string y_s = to_string(y);
                reverse(x_s.begin(), x_s.end());
                reverse(y_s.begin(), y_s.end());
                int x_inv = atoi(x_s.c_str());
                int y_inv = atoi(y_s.c_str());
                // print(x_inv);
                // print(y_inv);
                // print("");
                // break;

                if(x < y){
                    x = x_inv;
                }else{
                    y = y_inv;
                }
                if(x < y){
                    y = y - x;
                }else{
                    x = x - y;
                }
                count++;
                if(count >= 100){
                    total++;
                    print(i);
                    print(j);
                    print("");
                    break;
                    
                }
            }
            
        }
    }
    print(total);
}
