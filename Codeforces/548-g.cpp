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
    ll N, Q;
    cin >> N >> Q;
    ll a[200010];
    rep(i,0,N) cin >> a[i];
    vector<ll> pos[200010];
    rep(i,0,N){
        pos[a[i]].push_back(i);
    }
    ll plus[200010] = {};
    rep(n,0,200001){
        if(pos[n].size() >= 2){
            ll m = pos[n].size();
            plus[pos[n][0]]++;
            plus[pos[n][m-1]]--;
        }
    }
    ll cur = 0;
    vector<lpair> tt;
    ll st = 0;
    rep(i,0,N){
        cur += plus[i];
        if(cur == 0){
            tt.push_back(make_pair(st, i));
            st = i+1;
        }
    }
    // rep(i,0,tt.size()) cout << tt[i].first << " " << tt[i].second << " ";
    ll ans = 0;

    for(auto &e: tt){
        ll lv = e.first, rv = e.second;
        map<ll,ll> mp;
        rep(i,lv,rv+1){
            mp[a[i]]++;
        }
        ll max_val = 0;
        for(auto &e2: mp){
            max_val = max(max_val, e2.second);
        }
        ans += (rv - lv + 1) - max_val;

    }
    print(ans);
    // printa(tt, tt.size());

}