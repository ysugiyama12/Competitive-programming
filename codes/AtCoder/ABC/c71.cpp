
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
    ll A[100010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }

    sort(A, A+N, greater<int>());
    ll l1 = -1;
    ll l2 = -1;
    ll val_prev = A[0];
    rep(i,1,N){
        if(A[i] == val_prev && l1 == -1){
            l1 = A[i];
            val_prev = -1;
        }else if(A[i] == val_prev && l1 != -1 && l2 == -1){
            l2 = A[i];
            ll ans = l1 * l2;
            print(ans);
            return 0;
        }else{
            val_prev = A[i];
        }

    }
    print(0);

}
