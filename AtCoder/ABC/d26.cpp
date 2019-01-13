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
    int A,B,C;
    cin >> A >> B >> C;
    float left = -0.1;
    float right = 1e9;
    while(1){
        float m = (left+right)/2;
        print(m);
        float val = float(A) * m + float(B) * sin(m * float(C) * M_PI);
        if(val >= 100){
            right = m;
        }else{
            left = m;
        }
        if(abs(val - 100) <= 1e-7) break;

    }
    print(left);
}
