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

ll pow_mod(ll N, ll M, ll P){
    if(P == 0){
        return 1;
    }
    if(P % 2 == 1){
        return N * pow_mod(N, M, P-1) % M; 
    }else{
        ll tmp = pow_mod(N, M, P/2);
        return tmp * tmp % M;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,P;
    cin >> N >> M >> P;
    print(pow_mod(N, M, P));

}
