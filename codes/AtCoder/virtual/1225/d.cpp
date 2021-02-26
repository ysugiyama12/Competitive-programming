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
    ll A[200010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    ll lv = 0;
    ll left_value = A[0], right_value = 0;
    // ll diff = abs(A[0]-A[1]);
    ll diff_max[200010] = {};
    ll diff_min[200010] = {};
    rep(mid,1,N-2){
        right_value += A[mid];
        while(mid - lv > 1){
            // print(abs(right_value - left_value));
            // print(abs(right_value - left_value - 2 * A[lv]));
            if(abs(right_value - left_value) > abs(right_value - left_value - 2 * A[lv+1])){
                lv++;
                right_value -= A[lv];
                left_value += A[lv];
            }else{
                break;
            }
        }
        diff_max[mid] = max(right_value, left_value);
        diff_min[mid] = min(right_value, left_value);
    }
    left_value = 0, right_value = A[N-1];
    ll diff_max2[200010] = {};
    ll diff_min2[200010] = {};
    lv = N-2;

    rrep(mid, N-3, 1){
        left_value += A[mid+1];
        while(lv - mid > 1){
            if(abs(right_value - left_value) > abs(right_value - left_value + 2*A[lv])){
                right_value += A[lv];
                left_value -= A[lv];
                lv--;
            }else{
                break;
            }
        }
        diff_max2[mid] = max(right_value, left_value);
        diff_min2[mid] = min(right_value, left_value);
    }
    ll ans = INF;
    rep(i,1,N-2){
        ll max_val = max(diff_max[i], diff_max2[i]);
        ll min_val = min(diff_min[i], diff_min2[i]);
        ans = min(ans, max_val - min_val);
    }
    print(ans);
}
