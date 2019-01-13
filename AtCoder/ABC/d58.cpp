#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

ll pow_mod(ll N, ll M, ll P){
    if(P == 0) return 1;
    if(P % 2 == 1){
        return N * pow_mod(N,M,P-1) % M;
    }else{
        ll tmp = pow_mod(N,M,P/2);
        return tmp * tmp % M;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    const ll MOD = 1e9 + 7;
    ll x[100010], y[100010];
    rep(i,0,N){
        cin >> x[i];
    }
    rep(i,0,M){
        cin >> y[i];
    }
    ll ans_x = 0, ans_y = 0;
    rep(i,0,N){
        ans_x += (2 * i - N + 1) * x[i];
        ans_x %= MOD;
    }
    rep(i,0,M){
        ans_y += (2 * i - M + 1) * y[i];
        ans_y %= MOD;
    }
    ll ans = ans_x * ans_y % MOD;
    print(ans);

}
