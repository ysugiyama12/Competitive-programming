#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll D[55][55];
    cin >> N;
    rep(i,0,N){
        rep(j,0,N){
            cin >> D[i][j];
        }
    }
    ll Q;
    ll P[3000];
    cin >> Q;
    rep(i,0,Q){
        cin >> P[i];
    }
    ll sum[55][55] = {};
    rep(i,0,N){
        rep(j,0,N){
            sum[i][j+1] = sum[i][j] + D[i][j];
        }
    }

    printa2(sum, N+2, N+2);
    print("--");
    rep(j,0,N){
        rep(i,0,N){
            sum[i+1][j] = sum[i][j] = D[i][j];
        }
    }
    printa2(sum, N+2, N+2);

}
