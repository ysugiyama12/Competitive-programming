#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x[3], y[3];
    rep(i,0,3){
        cin >> x[i] >> y[i];
    }
    vector<lpair> lp;
    rep(i,0,3){
        lp.push_back(make_pair(x[i], y[i]));
    }
    sort(lp.begin(), lp.end());
    ll x_mid = lp[1].first;
    ll y_max = max(y[0], max(y[1], y[2]));
    ll y_min = min(y[0], min(y[1], y[2]));
    map<lpair, ll> mp;
    rep(x,lp[0].first, x_mid+1){
        mp[make_pair(x, lp[0].second)] = 1;
    }
    rep(x,x_mid, lp[2].first+1){
        mp[make_pair(x, lp[2].second)] = 1;
    }
    rep(y,y_min, y_max+1){
        mp[make_pair(lp[1].first, y)] = 1;
    }
    ll sz = mp.size();
    print(sz);
    for(auto &e: mp){
        cout << e.first.first << " " << e.first.second << endl;
    }
    // rep(i,0,1001){
    //     rep(j,0,1001){
    //         if(mp[make_pair(i,j)] == 1){
    //             cout << i << " " << j << endl;
    //         }
    //     }
    // }
}
