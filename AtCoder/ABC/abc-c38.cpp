#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
#define make_pair mp
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
    ll diff[100010] = {};
    rep(i,0,N-1){
        diff[i] = a[i+1] - a[i];
    }
    ll ans = 0;
    ans += N;
    ll cnt = 0;
    rep(i,0,N-1){
        if(diff[i] > 0){
            cnt++;
        }else{
            if(cnt > 0){
                ans += (cnt + 1) * cnt / 2;
                cnt = 0;
            }
        }

    }
    if(cnt > 0){
        ans += (cnt + 1) * cnt / 2;
    }
    print(ans);
}
