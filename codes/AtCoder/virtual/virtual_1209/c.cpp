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
    ll N,K;
    cin >> N >> K;
    ll a[100010];
    rep(i,0,N){
        cin >> a[i];
    }
    ll sum[100010] = {};
    ll sum_plus[100010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + a[i];
        if(a[i] > 0){
            sum_plus[i+1] = sum_plus[i] + a[i];
        }else{
            sum_plus[i+1] = sum_plus[i];
        }
    }
    ll ans = -INF;
    rep(i,0,N-K+1){
        ll tt = 0;
        tt += sum[K+i]-sum[i];
        tt += sum_plus[N] - sum_plus[K+i];
        tt += sum_plus[i];
        ans = max(ans,tt);
    }
    rep(i,0,N-K+1){
        ll tt = 0;
        tt += sum_plus[N] - sum_plus[K+i];
        tt += sum_plus[i];
        ans = max(ans,tt);
    }
    print(ans);
}
