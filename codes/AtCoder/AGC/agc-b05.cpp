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
    ll a[200010];
    cin >> N;
    rep(i,0,N) cin >> a[i];
    map<ll,ll> mp;
    rep(i,0,N) mp[a[i]] = i;
    ll pre[200010] = {}, ne[200010] = {};
    rep(i,0,N){
        pre[i] = i-1;
        ne[i] = i+1;
    }
    ll ans = 0;
    rrep(i,N,1){
        ll pos = mp[i];
        ans += i * (pos - pre[pos]) * (ne[pos] - pos);
        pre[ne[pos]] = pre[pos];
        ne[pre[pos]] = ne[pos];
    }
    print(ans);

}
