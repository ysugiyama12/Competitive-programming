#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
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
    ll lv = 0, rv = 1e18;
    while(rv - lv > 1){
        ll mid = (lv + rv)/2;
        print(mid);
        ll aa[55];
        rep(i,0,N){
            aa[i] = a[i];
        }
        rep(i,0,N){
            aa[i] += mid;
        }
        sort(aa, aa+N);
        ll vv = min(N,mid);
        rep(i,0,vv){
            aa[i] -= N+1;
        }
        bool is_ok = true;
        rep(i,0,N){
            if(aa[i] > N) is_ok = false;
        }
        printa(aa,N);
        // print(is_ok);
        if(is_ok){
            lv = mid;
        }else{
            rv = mid;
        }

    }
    print(lv);

}
