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
    ll a[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    sort(a,a+N);
    ll sum[100010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + a[i];
    }
    ll ans = 0;
    for(int i = N-1; i >= 0; i--){
        if(i == N-1){
            ans++;
        }else{
            ll val = sum[i+1];
            if(val * 2 >= a[i+1]){
                ans++;
            }else{
                print(ans);
                return 0;
            }
        }
    }
    print(ans);

}
