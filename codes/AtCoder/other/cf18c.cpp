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
const int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    ll A[55];
    cin >> N >> K;
    rep(i,0,N){
        cin >> A[i];
    }
    ll num_divide[55] = {};
    rep(i,0,N){
        ll n = A[i];
        while(n > 0){
            n /= 2;
            num_divide[i]++;
        }

    }
    sort(num_divide, num_divide + N);
        
    int sum = 0;
    rep(i,0,N){
        sum += num_divide[i];
    }



}
