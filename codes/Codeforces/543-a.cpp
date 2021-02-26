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
    ll N,M,K;
    cin >> N >> M >> K;
    ll p[110];
    rep(i,0,N) cin >> p[i];
    ll s[110];
    rep(i,0,N) cin >> s[i];
    ll c[110];
    rep(i,0,K) cin >> c[i];
    map<ll,ll> mp;
    rep(i,0,N){
        mp[s[i]] = max(mp[s[i]], p[i]);
    }
    ll ans = 0;
    rep(i,0,K){
        c[i]--;
        if(mp[s[c[i]]] != p[c[i]]) ans++;
    }
    print(ans);
}
