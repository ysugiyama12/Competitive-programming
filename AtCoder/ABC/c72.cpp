
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
    int a[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    sort(a, a+N);
    int mx = *max_element(a, a+N);
    int ans = 0;
    rep(i,0,mx+1){
        int cnt = upper_bound(a, a+N, i+1) - lower_bound(a, a+N, i-1);
        ans = max(ans, cnt);
    }
    print(ans);

}
