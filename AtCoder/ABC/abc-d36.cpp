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
ll N;
ll a[100010], b[100010];
vector<ll> tree[100010];
ll f[100010] = {}, g[100010] = {};
ll calc_f(ll, ll);

ll calc_g(ll pos, ll p){
    if(g[pos] != 0) return g[pos];
    g[pos] = 1;
    for(auto &e : tree[pos]){
        if(e != p){
            g[pos] *= calc_f(e, pos);
            g[pos] %= MOD;
        }
    }
    return g[pos];
}

ll calc_f(ll pos, ll p){
    if(f[pos] != 0) return f[pos];
    f[pos] += calc_g(pos, p);
    f[pos] %= MOD;
    ll tt = 1;
    for(auto &e : tree[pos]){
        if(e != p){
            tt *= calc_g(e, pos);
            tt %= MOD;
        }
    }
    f[pos] += tt;
    f[pos] %= MOD;
    return f[pos];

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    ll ans = calc_f(0, -1);
    ans %= MOD;
    print(ans);
}
