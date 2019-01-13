#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
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
    ll MOD = 1e9 + 7;
    cin >> N;
    ll cnt[1010] = {};
    rep(i,2,N+1){
        ll num = i;
        rep(j,2,1001){
            while(num % j == 0){
                cnt[j]++;
                num /= j;
            }
        }
    }
    ll ans = 1;
    rep(i,0,1001){
        if(cnt[i] != 0){
            ans *= cnt[i]+1;
            ans %= MOD;
        }
    }
    print(ans);
}
