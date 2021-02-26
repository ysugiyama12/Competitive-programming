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
    int s[110];
    cin >> N;
    rep(i,0,N){
        cin >> s[i];
    }
    sort(s, s+N);
    int sum = 0;
    rep(i,0,N){
        sum += s[i];
    }
    if(sum % 10 != 0){
        print(sum);
    }else{
        rep(i,0,N){
            if(s[i] % 10 != 0){
                sum -= s[i];
                print(sum);
                return 0;
            }
        }
        print(0);
    }

}
