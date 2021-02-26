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
int tt[31][100010] = {};
int sum[100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    int s[100010], t[100010], c[100010];
    rep(i,0,N){
        cin >> s[i] >> t[i] >> c[i];
        c[i]--;
    }
    rep(i,0,N){
        rep(j,s[i],t[i]+1){
            tt[c[i]][j] = 1;
        }
    }
    // printa2(tt, C, 20);
    rep(i,0,100010){
        rep(j,0,C){
            sum[i] += tt[j][i];
        }
    }
    int ans = 0;
    rep(i,0,100010){
        ans = max(ans, sum[i]);
    }
    // printa(sum,20);
    print(ans);
    


}
