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
ll a[1010][1010] = {};
ll cnt[1010][1010] = {};
ll H,W;
ll dy[4] = {0,0,1,-1};
ll dx[4] = {1,-1,0,0};

ll calc(ll y, ll x){
    if(cnt[y][x] != 0) return cnt[y][x];
    cnt[y][x] = 1;
    rep(i,0,4){
        ll ny = y + dy[i];
        ll nx = x + dx[i];
        if(nx >= 0 && nx < W && ny >= 0 && ny < H && a[y][x] < a[ny][nx]){
            cnt[y][x] += calc(ny,nx);
            cnt[y][x] %= MOD;
        }
    }
    return cnt[y][x];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    rep(i,0,H){
        rep(j,0,W){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    rep(i,0,H){
        rep(j,0,W){
            ans += calc(i,j);
            ans %= MOD;
        }
    }
    print(ans);

}
