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
    int N,M,A,B;
    int l[110], r[110];
    cin >> N >> M >> A >> B;
    rep(i,0,M){
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    int is_a[110] = {};
    rep(i,0,M){
        rep(j, l[i], r[i]+1){
            is_a[j] = 1;
        }
    }
    ll ans = 0;
    rep(i,0,N){
        if(is_a[i] == 1){
            ans += A;
        }else{
            ans += max(A,B);
        }
    }
    print(ans);

}
