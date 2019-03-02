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
    ll A,B,Q;
    ll s[100010], t[100010], x[100010];
    cin >> A >> B >> Q;
    rep(i,1,A+1) cin >> s[i];
    rep(i,1,B+1) cin >> t[i];
    rep(i,0,Q) cin >> x[i];
    s[0] = -INF; s[A+1] = INF;
    t[0] = -INF; t[B+1] = INF;
    rep(i,0,Q){
        ll ans = INF;
        ll p1 = lower_bound(s, s+A+2, x[i]) - s;
        ll p2 = lower_bound(t, t+B+2, x[i]) - t;
        ans = min(ans, max(s[p1] - x[i], t[p2] - x[i]));
        ans = min(ans, max(x[i] - s[p1-1], x[i] - t[p2-1]));
        ans = min(ans, s[p1] - t[p2-1] + min(s[p1]-x[i], x[i]-t[p2-1]));
        ans = min(ans, t[p2] - s[p1-1] + min(t[p2]-x[i], x[i]-s[p1-1]));
        print(ans);
    }
}
