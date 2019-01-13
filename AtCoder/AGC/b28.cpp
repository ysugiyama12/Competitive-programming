#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
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
    ll A[100010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    ll sum[100010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + A[i];
    }
    ll frac[100010] = {};
    frac[0] = 1;
    frac[1] = 1;
    rep(i,2,N+1){
        frac[i] = frac[i-1] * i % MOD;
    }
    ll ans = 0;
    rep(i,0,N){
        ll val = 1;
        ans += val * A[i] % MOD;
    }
    print(ans);

}
