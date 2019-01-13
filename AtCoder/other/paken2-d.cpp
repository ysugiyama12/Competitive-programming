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
    ll C[100010];
    cin >> N;
    rep(i,0,N-1){
        cin >> C[i];
    }
    ll sum[100010] = {};
    rep(i,0,N-1){
        sum[i+1] = sum[i] + C[i];
    }
    ll ans[100010];
    rep(i,0,N){
        ans[i] = 0;
    }
    ll sum_max[100010] = {};
    rep(i,0,N+1){
        sum_max[i] = -INF;
    }
    rrep(i, N-1, 0){
        sum_max[i] = max(sum_max[i+1], sum[i]);
    }
    rep(i,0,N){
        ans[i] = max(ans[i], sum_max[i] - sum[i]);
    }
    ll sum_max2[100010] = {};
    rep(i,0,N){
        sum_max2[i] = INF;
    }
    sum_max2[0] = 0;
    rep(i,1,N){
        sum_max2[i] = min(sum_max2[i-1], sum[i]);
    }
    rep(i,0,N){
        ans[i] = max(ans[i], sum[i] - sum_max2[i]);
    }
    // printa(sum_max, N);
    // printa(sum_max2, N);
    printa(ans, N);
    // printa(sum_max, N);

}
