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
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    ll dx = tx - sx;
    ll dy = ty - sy;
    rep(i,0,dy){
        cout << 'U';
    }
    rep(i,0,dx){
        cout << 'R';
    }
    rep(i,0,dy){
        cout << 'D';
    }
    rep(i,0,dx){
        cout << 'L';
    }
    cout << 'L';
    rep(i,0,dy+1){
        cout << 'U';
    }
    rep(i,0,dx+1){
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    rep(i,0,dy+1){
        cout << 'D';
    }
    rep(i,0,dx+1){
        cout << 'L';
    }
    cout << 'U' << endl;
}
