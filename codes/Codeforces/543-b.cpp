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
    ll N;
    cin >> N;
    ll a[1010];
    rep(i,0,N) cin >> a[i];
    map<ll,ll> mp;
    rep(i,0,N){
        rep(j,0,N){
            if(i == j)continue;
            mp[a[i] + a[j]]++;
        }
    }
    ll ans = 0;
    for(auto &e: mp){
        ans = max(ans, e.second);
    }
    print(ans/2);
}
