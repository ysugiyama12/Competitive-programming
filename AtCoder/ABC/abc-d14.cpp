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
ll N,Q;
ll x[100010], y[100010];
ll a[100010], b[100010];
vector<ll> tree[100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    rep(i,0,N-1){
        tree[x[i]].push_back(y[i]);
        tree[y[i]].push_back(x[i]);
    }
    cin >> Q;
    rep(i,0,Q){
        cin >> a[i] >> b[i];
    }
    

}
