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
    ll d[100010];
    rep(i,0,N) cin >> d[i];
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(d[i], 2*i+1));
    }
    sort(lp.begin(), lp.end(), greater<lpair>());
    vector<lpair> ans;
    vector<ll> pos;
    rep(i,0,N){
        pos.push_back(lp[i].second);
    }
    rep(i,0,N-1){
        ans.push_back(make_pair(lp[i].second, lp[i+1].second));
    }
    rep(i,0,N){
        ll v = i + lp[i].first - 1;
        ans.push_back(make_pair(pos[v], lp[i].second+1));
        if(v == (ll)pos.size()-1){
            pos.push_back(lp[i].second+1);
        }
    }
    for(auto &e: ans){
        cout << e.first << " " << e.second << endl;
    }


    
}