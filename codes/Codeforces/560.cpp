#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll K[200010];
    rep(i,0,N) cin >> K[i];
    ll d[200010], t[200010];
    rep(i,0,M) cin >> d[i] >> t[i];
    vector<lpair> lp;
    rep(i,0,M) lp.push_back(make_pair(d[i], t[i]-1));
    sort(lp.begin(), lp.end());
    ll lv = 0, rv = 400010;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        print(mid);
        ll kt[200010] = {};
        rep(i,0,N) kt[i] = K[i];
        ll cost = 0;
        ll money = 0;
        rep(i,0,M){
            ll day = lp[i].first;
            ll idx = lp[i].second;
            if(kt[idx] == 0) continue;
            if()


        }
        // rep(i,0,M){
        //     if(d[i] <= mid && kt[t[i]-1] != 0){
        //         cost += kt[t[i]-1];
        //         kt[t[i]-1] = 0;
        //     }
        // }
        // rep(i,0,N){
        //     if(kt[i] != 0) cost += 2 * kt[i];
        // }
        // if(cost <= mid){
        //     rv = mid;
        // }else{
        //     lv = mid;
        // }
    }
    print(rv);



    
}