#include <bits/stdc++.h>
#include <unordered_map>
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
ll n,k,A,B;
ll a[100010];
unordered_map<ll,ll> mp;
ll idx = 0;
// map<lpair, ll> dp;
ll sum[100010] = {}, pos[100010] = {};
ll rec(ll lv, ll rv){
    // if(dp[make_pair(lv,rv)] != 0){
    //     return dp[make_pair(lv,rv)];
    // }
    if(lv == rv){
        if(mp[lv] == 0){
            return A;
        }else{
            return 1 * mp[lv] * B;
        }
    }
    ll val = 0;
    ll enemy = 0;
    ll p1 = upper_bound(pos, pos+k+1, rv) - pos;
    ll p2 = lower_bound(pos, pos+k+1, lv) - pos;
    enemy = sum[p1-1] - sum[p2-1]; 
    if(enemy == 0){
        val = A;
    }else{
        val = (rv - lv + 1) * enemy * B;
    }
    if(enemy == 0) return val;
    ll v = (rv - lv+1)/2;
    val = min(val, rec(lv, lv+v-1) + rec(lv+v, rv));
    return val;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k >> A >> B;
    rep(i,0,k) cin >> a[i];
    rep(i,0,k) mp[a[i]]++;
    sort(a, a+k);
    // printa(a,k);
    rep(i,0,k){
        sum[i+1] = sum[i] + 1;
        pos[i+1] = a[i];
    }
    // printa(pos,k+2);
    // printa(sum, k+1);
    ll ans = rec(1, (1LL<<n));
    print(ans);
    return (0^_^0);

}
