/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[2010];
    rep(i,0,N) cin >> a[i];
    map<ll,ll> mp;
    rep(i,0,N) mp[a[i]]++;
    map<ll,ll> cur;
    ll lv = 0, rv = 0;
    ll ans = INF;
    while(1){
        bool ok = true;
        for(auto &e: mp){
            if(e.second - cur[e.first] > 1) ok = false;
        }
        if(ok){
            ans = min(ans, rv - lv);
            if(lv == rv){
                print(0);
                return 0;
            }else{
                lv++;
                cur[a[lv-1]]--;
            }
        }else{
            rv++;
            if(rv == N+1) break;
            cur[a[rv-1]]++;
        }
    }
    print(ans);

}