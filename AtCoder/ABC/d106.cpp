#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;
ll L[200010], R[200010];
ll p[100010], q[100010];
ll tt[510][510] = {};
ll sum[510][510] = {};
ll tt_ans[510][510] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,Q;
    cin >> N >> M >> Q;
    rep(i,0,M){
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }
    rep(i,0,Q){
        cin >> p[i] >> q[i];
        p[i]--;
        q[i]--;
    }



    rep(i,0,M){
        tt[L[i]][R[i]]++;
    }


    rep(i,0,N){
        rep(j,1,N+1){
            sum[i][j] = sum[i][j-1] + tt[i][j-1];
        }
    }

    rep(i,0,N){
        rep(j,0,N){
            rep(k,i,j+1){
                tt_ans[i][j] += sum[k][j+1] - sum[k][i];
            }
        }
    }
    rep(i,0,Q){
        ll count = 0;
        ll ans = tt_ans[p[i]][q[i]];
        print(ans);
    }
}
