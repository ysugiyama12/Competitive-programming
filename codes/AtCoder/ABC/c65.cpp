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
const ll MOD = 1e9 + 7;
ll factorial(ll N){
    ll val = 1;
    rep(i,1,N+1){
        val *= i;
        val %= MOD;
    }
    return val;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    ll ans = 0;
    if(N == M){
        ans = factorial(N) * factorial(M) % MOD;
        ans *= 2;
        ans %= MOD;
    }else if(abs(N - M) == 1){
        ans = factorial(N) * factorial(M) % MOD;
    }else{
        ans = 0;
    }
    print(ans);

}
