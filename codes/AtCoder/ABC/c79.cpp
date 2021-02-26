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
    string S;
    cin >> S;
    int num[4] = {S[0] - '0',S[1] - '0',S[2] - '0',S[3] - '0'};
    rep(i,0,(1<<3)){
        int ans = num[0];
        rep(j,0,3){
            ans += (i >> j & 1 ? num[j+1] : num[j+1] * -1);
        }
        if(ans == 7){
            cout << num[0];
            rep(j,0,3){
                cout << (i >> j & 1 ? '+' : '-');
                cout << num[j+1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
}
