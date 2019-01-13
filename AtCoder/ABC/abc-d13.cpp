#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll d[41][100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,D;
    cin >> N >> M >> D;
    ll A[200010];
    rep(i,0,M){
        cin >> A[i];
        A[i]--;
    }
    vector<ll> pos;
    rep(i,1,N+1){
        pos.push_back(i);
    }
    rep(i,0,M){
        swap(pos[A[i]], pos[A[i]+1]);
    }
    // printa(pos, N);
    ll mv[100010] = {};
    rep(i,0,N){
        d[0][pos[i]-1] = i+1;
    }
    // printa(d[0],N);
    // rep(i,0,N){
    //     d[0].push_back(mv[i]);
    // }
    rep(n,1,40){
        rep(i,0,N){
            d[n][i] = d[n-1][d[n-1][i]-1];
        }
    }
    // 15= 1 + 2 + 4 + 8;
    // ll ans[100010];
    // printa(d[1],N);
    rep(i,0,N){
        ll val = i+1;
        rep(j,0,40){
            ll num = (D & (1L<<j));
            // print(j);
            // print(num);
            // print("--");
            if(num != 0){
                val = d[j][val-1];
            }
        }
        print(val);
        // ans[val-1] = i+1;
    }
    // printa(d[0],N);
    // printa(d[1],N);
    // printa(d[2],N);
}
