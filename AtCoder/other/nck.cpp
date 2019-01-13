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
int N,K;
ll v[51][51];

void nck(){
    rep(i,0,N+1){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    rep(i,1,N+1){
        rep(j,1,i){
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    nck();
    print(v[N][K]);

}
