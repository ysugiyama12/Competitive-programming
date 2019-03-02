#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a[8];
    rep(i,0,7) cin >> a[i];
    ll ans = 0;
    ans += a[1];
    // print2(v1,v4);
    ll tt = 0;
    if(a[0] >= 1 && a[3] >= 1 && a[4] >= 1){
        tt += 3;
        tt += 2 * ((a[0]-1)/2) + 2 * ((a[3]-1)/2) + 2 * ((a[4]-1)/2);
    }
    ll tt2 = 2 * (a[0]/2) + 2 * (a[3]/2) + 2 * (a[4]/2);
    ans += max(tt, tt2);
    print(ans);
}
