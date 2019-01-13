#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
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
    int N;
    string S;
    cin >> N;
    cin >> S;
    int left_kakko = 0;
    int right_kakko = 0;
    rep(i,0,N){
        if(S[i] == '('){
            left_kakko++;
        }else{
            if(left_kakko != 0){
                left_kakko--;
            }else{
                right_kakko++;
            }
        }
    }
    rep(i,0,right_kakko){
        cout << '(';
    }
    cout << S;
    rep(i,0,left_kakko){
        cout << ')';
    }
    cout << endl;

}
