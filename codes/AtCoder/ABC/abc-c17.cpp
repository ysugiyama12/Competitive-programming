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
    ll l[100010], r[100010], s[100010];
    cin >> N >> M;
    rep(i,0,N){
        cin >> l[i] >> r[i] >> s[i];
    }
    ll sum = 0;
    rep(i,0,N){
        sum += s[i];
    }
    ll ans = 0;
    ll val[100010] = {};
    rep(i,0,N){
        val[l[i]-1] += s[i];
        val[r[i]] -= s[i];
    }
    rep(i,1,M+1){
        val[i] += val[i-1];
    }
    rep(i,1,M+1){
        ll tt = 0;
        ans = max(ans, sum - val[i-1]);
    }
    print(ans);

}
