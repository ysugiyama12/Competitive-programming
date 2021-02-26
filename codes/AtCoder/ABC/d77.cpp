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

int calc(ll k){
    int ans = 0;
    while(k > 0){
        ans += k % 10;
        k /= 10;
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    rep(i,0,100){
        ll k = K * (i+1);
        int cnt = calc(k);
        print(cnt);
    }

}
