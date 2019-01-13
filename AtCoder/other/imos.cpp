#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,W,H;
    int A[10],B[10],C[10],D[10];
    cin >> N >> W >> H;
    rep(i,0,N){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    ll tiles[100][100] = {};
    rep(i,0,N){
        tiles[A[i]][C[i]]++;
        tiles[A[i]][D[i]+1]--;
        tiles[B[i]+1][C[i]]--;
        tiles[B[i]+1][D[i]+1]++;
    }
    rep(y,0,H){ rep(x,0,W){
            cout << tiles[y][x] << " ";
        }
        cout << endl;
    }
    rep(y,0,H){
        rep(x,1,W){
            tiles[y][x] += tiles[y][x-1];
        }
    }
    rep(y,1,H){
        rep(x,0,W){
            tiles[y][x] += tiles[y-1][x];
        }
    }
    ll tile_max = 0;
    rep(y,0,H){
       rep(x,0,W){
           tile_max = max(tile_max, tiles[y][x]);
       }
    }
    rep(y,0,H){ rep(x,0,W){
            cout << tiles[y][x] << " ";
        }
        cout << endl;
    }
    print(tile_max);












}
