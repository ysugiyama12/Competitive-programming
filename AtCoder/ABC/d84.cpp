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
int l[100010], r[100010];
int is_prime[100010] = {};
int sum[100010] = {};

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N = 100000;
    int Q;
    cin >> Q;
    rep(i,0,Q){
        cin >> l[i] >> r[i];
    }
    rep(i,2,N+1){
        if(i % 2 == 1){
            is_prime[i] = (IsPrime(i) && IsPrime((i+1)/2) ? 1 : 0);
        }
    }
    rep(i,1,N+2){
        sum[i] = sum[i-1] + is_prime[i-1];
    }
    rep(i,0,Q){
        ll ans = sum[r[i] + 1] - sum[l[i]];
        print(ans);
    }

}
