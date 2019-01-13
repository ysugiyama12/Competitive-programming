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
    ll N,M;
    ll X,Y;
    ll a[100010], b[100010];
    cin >> N >> M;
    cin >> X >> Y;
    rep(i,0,N){
        cin >> a[i];
    }
    rep(i,0,M){
        cin >> b[i];
    }
    ll idx_a = 0;
    ll idx_b = 0;
    ll tt = 0;
    ll ans = 0;
    while(1){
        if(idx_a == N || idx_b == M) break;
        while(a[idx_a] < tt && idx_a <= N-1){
            idx_a++;
        }
        if(idx_a == N) break;
        tt = a[idx_a] + X;
        idx_a++;
        while(b[idx_b] < tt && idx_b <= M-1){
            idx_b++;
        }
        if(idx_b == M) break;
        tt = b[idx_b] + Y;
        idx_b++;
        ans++;
    }
    print(ans);

}
