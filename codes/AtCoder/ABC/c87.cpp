#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
typedef long long ll;
typedef struct{
    int x;
    int y
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    int A[2][101] = {};
    rep(i,0,2){
        rep(j,0,N){
            cin >> A[i][j];
        }
    }
    int ans = 0;
    rep(i,0,N){
        int ans_tmp = 0;
        rep(j,0,i+1){
            ans_tmp += A[0][j];
        }
        rep(j,i,N){
            ans_tmp += A[1][j];
        }
        ans = max(ans, ans_tmp);

    }
    print(ans);
}
