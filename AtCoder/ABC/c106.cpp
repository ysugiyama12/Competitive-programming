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
    string S;
    ll K;
    cin >> S >> K;
    int n = S.size();
    char tt[101];
    rep(i,0,101){
        tt[i] = '0';
    }
    rep(i,0,n){
        if(S[i] == '1'){
            tt[i] = '1';
        }else{
            rep(j,i,100){
                tt[j] = S[i];
            }
            break;
        }
    }
    if(K <= 100){
        print(tt[K-1]);
    }else{
        print(tt[99]);
    }
}
