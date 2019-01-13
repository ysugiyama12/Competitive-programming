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
vector<ll> v;
ll and_sum[1000 * 1000 + 10];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    ll a[1010];
    cin >> N >> K;
    rep(i,0,N){
        cin >> a[i];
    }
    ll sum[1010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + a[i];
    }
    rep(i,0,N+1){
        rep(j,0,N+1){
            if(i != j && i < j){
                v.push_back(sum[j] - sum[i]);

            }
        }
    }
    ll nn = N * (N+1) / 2;
    ll ans = 0;
    for(int t = 42; t >= 0; t--){
        ll cnt = 0;
        rep(i,0,nn){
            ll val = (1L<<t) + ans;
            if((val & v[i]) == val){
                cnt++;
            }
        }
        if(cnt >= K){
            ans += (1L<<t);
        }
    }
    print(ans);



}
