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
ll val_a[200010] = {}, val_b[200010] = {}, val_c[200010] = {}, val_d[200010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[200010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    ll ans = INF;
    ll sum[200010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + A[i];
    }
    ll fi = 0;
    rep(i,1,N-2){
        while(fi+1 < i){
            ll lv = sum[fi+1];
            ll rv = sum[i+1] - sum[fi+1];
            ll lv_next = sum[fi+2];
            ll rv_next = sum[i+1] - sum[fi+2];
            if(abs(lv-rv) <= abs(lv_next - rv_next)) break;
            fi++;
        }
        val_a[i] = sum[fi+1];
        val_b[i] = sum[i+1] - sum[fi+1];
    }
    fi = N-2;
    for(int i = N-3; i >= 1; i--){
        while(fi - 1 > i){
            ll lv = sum[fi+1] - sum[i+1];
            ll rv = sum[N] - sum[fi+1];
            ll lv_next = sum[fi] - sum[i+1];
            ll rv_next = sum[N] - sum[fi];

            if(abs(lv -rv) <= abs(lv_next - rv_next)) break;
            fi--;
        }
        val_c[i] = sum[fi+1] - sum[i+1];
        val_d[i] = sum[N] - sum[fi+1];
    }
    rep(i,1,N-2){
        ll max_val = max(max(val_a[i],val_b[i]), max(val_c[i],val_d[i]));
        ll min_val = min(min(val_a[i],val_b[i]), min(val_c[i],val_d[i]));
        ans = min(ans, max_val-min_val);

    }
    print(ans);


}
