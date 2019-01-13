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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll a[1300], b[1300], v[1300];
    cin >> N;
    ll d[55][55] = {};
    ll dist[110] = {};
    rep(i,2,N+1){
        cout << "? " << 1 << " " << i << endl;
        ll val;
        cin >> val;
        dist[i] = val;
    }
    ll idx = -1;
    ll max_v = 0;
    rep(i,2,N+1){
        if(max_v < dist[i]){
            max_v = dist[i];
            idx = i;
        }
    }
    ll dist2[110] = {};
    rep(i,1,N+1){
        if(i != idx){
            cout << "? " << idx << " " << i << endl;
            ll val;
            cin >> val;
            dist2[i] = val;
        }
    }
    ll ans = 0;
    rep(i,1,N+1){
        ans = max(ans, dist2[i]);
    }
    cout << "! " << ans << endl;
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(i == j){
    //             d[i][j] = 0;
    //         }else{
    //             d[i][j] = INF;
    //         }
    //     }
    // }
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(i < j){
    //             cout << "? " << i+1 << " " << j+1 << endl;
    //             ll val;
    //             cin >> val;
    //             d[i][j] = val;
    //             d[j][i] = val;
    //         }
    //     }
    // }
    // ll ans = 0;
    // rep(i,0,N){
    //     rep(j,0,N){
    //         ans = max(ans, d[i][j]);
    //     }
    // }
    // cout << "! " << ans << endl;

}
