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
vector< vector<ll> > dp;
void vis_2d(vector< vector<ll> > v, ll h, ll w, ll pad=4){
    cout <<  "ij "; rep(i,0,w) cout << left << setw(pad) << i; cout << endl;
    rep(i,0,h){
        cout << i << ": ";
        rep(j,0,w){ if(v[i][j] == INF) cout << "x" << string(pad-1, ' '); else cout << left << setw(pad) << v[i][j]; }
        cout << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,W;
    ll w[110], v[110];
    cin >> N >> W;
    rep(i,0,N){
        cin >> w[i] >> v[i];
    }
    dp.resize(N+1, vector<ll> (W+2, 0));
    rep(i,0,N){
        rep(j,0,W+1){
            if(j - w[i] >= 0){
                dp[i+1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    vis_2d(dp, N+1, W+1);
    print(dp[N][W]);
}
