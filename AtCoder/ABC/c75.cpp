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
ll dist[60][60] = {};
ll dist_result[60][60] = {};
int N,M;
void floyd(){
    rep(i,0,N){
        rep(j,0,N){
            dist_result[i][j] = dist[i][j];
        }
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                dist_result[i][j] = min(dist_result[i][j], dist_result[i][k] + dist_result[k][j]);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false); 
    int a[55], b[55];
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    int ans = 0;
    rep(i,0,N){
        rep(j,0,N){
            if(i == j){
                dist[i][j] = 0;
            }else{
                dist[i][j] = INF;
            }
        }
    }
    rep(i,0,M){
        dist[a[i]][b[i]] = 1;
        dist[b[i]][a[i]] = 1;
    }
    floyd();

    rep(i,0,M){
        dist[a[i]][b[i]] = INF;
        dist[b[i]][a[i]] = INF;

        floyd();
        if(dist_result[a[i]][b[i]] > 1e5){
            ans++;
        }
        dist[a[i]][b[i]] = 1;
        dist[b[i]][a[i]] = 1;
    }
    print(ans);

}
