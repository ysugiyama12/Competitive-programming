#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[3010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    ll sum[3010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + A[i];
    }
    rep(i,1,N+1){
        ll ans = 0;
        rep(j,i,N+1){
            ans = max(ans, sum[j] - sum[j-i]);
        }
        print(ans);
    }
}
