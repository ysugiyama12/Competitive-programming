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
    int N;
    int A[100010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    sort(A, A+N);
    ll ans = 0;
    int cnt = 1;
    ll now_num = A[0];
    rep(i,1,N){
        if(A[i] == now_num){
            cnt++;
        }else{
            now_num = A[i];
            if(cnt % 2 == 1){
                ans++;
            }
            cnt = 1;
        }
    }
    if(cnt % 2 == 1){
        ans++;
    }
    print(ans);

}
