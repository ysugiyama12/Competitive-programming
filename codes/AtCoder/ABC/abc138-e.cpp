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
    string S,T;
    cin >> S >> T;
    ll ns = S.size(), nt = T.size();
    ll s_idx = 0;
    set<ll> st[26];
    map<ll, ll> mp;
    rep(i,0,ns){
        ll t = S[i] - 'a';
        mp[t]++;
        st[t].insert(i);
    }
    rep(i,0,nt){
        ll t = T[i] - 'a';
        if(mp[t] == 0){
            print(-1);
            return 0;
        }
    }
    ll ans = 0;
    rep(i,0,nt){
        ll t = T[i] - 'a';
        auto iter = st[t].lower_bound(s_idx);
        if(iter == st[t].end()){
            ans += ns - s_idx;
            s_idx = 0;
            auto iter2 = st[t].lower_bound(0);
            ll v = *iter2;
            ans += v+1;
            s_idx = v+1;
        }else{
            ll v = *iter;
            ans += v+1 - s_idx;
            s_idx = v+1;
        }

    }
    print(ans);

    
}