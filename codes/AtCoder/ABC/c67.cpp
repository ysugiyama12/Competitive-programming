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
    ll a[200010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    ll sum[200010] = {};
    rep(i,0,N){
        sum[i + 1] = sum[i] + a[i];
    }

    ll ans = 1e18;
    rep(i,0,N-1){
        ll x = sum[i+1];
        ll y = sum[N] - sum[i+1];
        ans = min(abs(x-y), ans);
    }
    print(ans);
}
