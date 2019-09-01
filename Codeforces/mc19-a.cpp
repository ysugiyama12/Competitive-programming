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
ll sum[2010][2010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[2010];
    rep(i,0,N) cin >> a[i];
    ll ans = INF;
    vector<ll> v;
    rep(i,0,N) v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll b[2010];
    rep(i,0,N){
        b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
    map<ll,ll> mp;
    rep(i,0,N) mp[b[i]]++;
    rep(i,0,N){
        sum[b[i]][i+1]++;
    }
    rep(i,0,N+1){
        rep(j,0,N){
            sum[i][j+1] += sum[i][j];
        }
    }
    rep(i,0,N+1){
        cout << sum[0][i] << " ";
    }
    cout << endl;
    rep(i,0,N){ //start
        ll max_val = 0;
        for(auto &e: mp){
            ll pos = lower_bound(sum[e.first], sum[e.first]+N, sum[e.first][i]+1) - sum[e.first];
            if(pos == N){
                max_val = INF;
                continue;
            }
            ll v = pos - i;
            max_val = max(max_val, v);
        }
        ans = min(ans, max_val);
        // print(ans);
    }
    print(ans);

    
}