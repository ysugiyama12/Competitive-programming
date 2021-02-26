#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;
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

    int N;
    cin >> N;
    int t[100001], x[100001], y[100001];
    rep(i,0,N){
        cin >> t[i] >> x[i] >> y[i];
    }
    bool is_ok = true;
    int bt = 0;
    int bx = 0;
    int by = 0;
    rep(i,0,N){
        int at = t[i];
        int dt = at-bt;
        int dx = x[i] - bx;
        int dy = y[i] - by;
        if(abs(dx) + abs(dy) > dt){
            is_ok = false;
        }else if((dt - abs(dx) - abs(dy)) % 2 == 1){
            is_ok = false;
        }

        bt = t[i];
        bx = x[i];
        by = y[i];
    }
    if(is_ok){
        print("Yes");
    }else{
        print("No");
    }
}
