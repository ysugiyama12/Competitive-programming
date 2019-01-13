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
ll N;
ll D[100010];
ll p_up[100010] = {};
ll up_sum[100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N){
        cin >> D[i];
    }
    sort(D, D+N);

    ll ans = 0;
    rep(i,0,N){
        ll p2 = lower_bound(D, D+N, D[i]*2) - D;
        p_up[i] = N - p2;
    }
    rep(i,0,N){
        up_sum[i+1] = up_sum[i] + p_up[i];
    }
    rep(i,0,N){
        ll p1 = upper_bound(D, D+N, D[i]/2) - D;
        ll p2 = lower_bound(D, D+N, D[i]*2) - D;
        ans += p1 * (up_sum[N] - up_sum[p2]) % MOD;
        ans %= MOD;
    }
    // if(N > 3000) return 0;
    // ll ans = 0;
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(i >= j) continue;
    //         ll v1 = D[i];
    //         ll v2 = D[j];
    //         if(v2 < 2*v1) continue;
    //         ll p1 = upper_bound(D, D+N, v1/2) - D;
    //         ll p2 = lower_bound(D, D+N,  v2*2) - D;
    //         ans += (N-p2) * p1 % MOD;
    //         ans %= MOD;
    //     }
    // }
    print(ans);

}
