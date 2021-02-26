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
    ll x[100010];
    rep(i,0,N) cin >> x[i];
    ll val[100010] = {};
    ll cur = 0;
    rep(i,0,N){
        if(i == 0){
            val[i] = cur;
        }else{
            ll prev = x[i-1];
            ll num = i - cur;
            if(prev < 2 * num - 1){
                cur++;
                val[i] = cur;
            }else{
                val[i] = cur;
            }
        }
    }
    ll ans = 1;
    rep(i,0,N){
        ll p = upper_bound(val, val+N, i) - val;
        ans *= (p-i);
        ans %= MOD;
    }
    print(ans);
}