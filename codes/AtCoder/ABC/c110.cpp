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
    string S,T;
    cin >> S >> T;
    int cnt_s[26] = {};
    int cnt_t[26] = {};
    int N = S.size();
    rep(i,0,N){
        int num = S[i] - 'a';
        cnt_s[num]++;
        num = T[i] - 'a';
        cnt_t[num]++;
    }
    sort(cnt_s, cnt_s + 26);
    sort(cnt_t, cnt_t + 26);
    rep(i,0,26){
        if(cnt_s[i] != cnt_t[i]){
            print("No");
            return 0;
        }
    }
    print("Yes");

}
