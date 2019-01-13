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
    double S;
    cin >> N >> S;
    ll a[100010], b[100010];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    vector<ll> tree[100010];
    rep(i,0,N-1){
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    ll cnt = 0;
    rep(i,0,N){
        if(tree[i].size() == 1) cnt++;
    }
    double ans = 2 * S / (double) cnt;
    cout << setprecision(10) << ans << endl;



}
