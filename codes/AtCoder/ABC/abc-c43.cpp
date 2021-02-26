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
    ll N;
    ll a[110];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    ll ave = 0;
    rep(i,0,N){
        ave += a[i];
    }
    ave /= N;
    ll ans = 1e9;
    rep(i, ave-1, ave + 2){
        ll ans_tmp = 0;
        rep(j,0,N){
            ans_tmp += (i - a[j]) * (i - a[j]);
        }
        ans = min(ans, ans_tmp);
    }
    print(ans);


}