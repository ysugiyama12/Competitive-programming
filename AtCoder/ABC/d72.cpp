
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
    int p[100010];
    cin >> N;
    rep(i,0,N){
        cin >> p[i];
    }
    int seq = 0;
    int ans = 0;
    rep(i,0,N){
        if(p[i] == i+1){
            seq++;
        }else{
            if(seq <= 1){
                ans += seq;
            }else{
                ans += (seq+1)/2;
            }
            seq = 0;
        }

    }
    if(seq <= 1){
        ans += seq;
    }else{
        ans += (seq+1)/2;
    }
    print(ans);


}
