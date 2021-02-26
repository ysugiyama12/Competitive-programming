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
    ll N,H;
    ll A,B,C,D,E;
    cin >> N >> H;
    cin >> A >> B >> C >> D >> E;
    ll ans = INF;
    rep(i,0,N+1){
        ll v1 = E*N - E*i - B*i - H;
        ll v2 = D+E;
        ll val;
        if(v1 < 0){
            val = 0;
        }else{
            val = v1/v2 + 1;
        }
        if(val > N-i) continue;
        ans = min(ans, A*i + C*val);
    }
    print(ans);

}
