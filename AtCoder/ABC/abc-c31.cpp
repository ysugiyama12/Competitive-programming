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
    ll a[55];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    ll ans = -INF;
    rep(i,0,N){
        ll vmax = -INF;
        ll pos = -1;
        ll tval = 0;
        rep(j,0,N){
            if(i != j){
                ll min_val = min(i,j);
                ll max_val = max(i,j);
                ll v1 = 0, v2 = 0;
                rep(k,min_val, max_val+1){
                    if((k - min_val) % 2 == 0){
                        v1 += a[k];
                    }else{
                        v2 += a[k];
                    }
                }
                if(v2 > vmax){
                    vmax = v2;
                    pos = j;
                    tval = v1;
                }
            }
        }
        ans = max(ans, tval);
    }
    print(ans);
}
