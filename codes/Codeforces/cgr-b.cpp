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
    ll N,M,K;
    ll b[100010];
    cin >> N >> M >> K;
    rep(i,0,N) cin >> b[i];
    ll ans = K;
    ll diff[100010];
    rep(i,0,N-1){
        diff[i] = b[i+1] - b[i];
    }
    sort(diff, diff+N-1, greater<ll>());
    // printa(diff,N-1);
    rep(i,K-1,N-1){
        // print(i);
        ans += diff[i];
    }
    print(ans);


}
