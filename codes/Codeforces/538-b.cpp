#include <bits/stdc++.h>
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,K;
    cin >> N >> M >> K;
    ll a[200010];
    rep(i,0,N) cin >> a[i];
    vector<lpair> lp;
    rep(i,0,N) lp.push_back(make_pair(a[i], i));
    sort(lp.begin(), lp.end(), greater<lpair>());
    ll pos[200010] = {};
    ll ans = 0;
    rep(i,0,M*K){
        ll idx = lp[i].second;
        pos[idx] = 1;
        ans += lp[i].first;
    }
    ll cnt = 0;
    vector<ll> tt;
    rep(i,0,N){
        if(pos[i] == 1){
            cnt++;
        }
        if(cnt == M){
            tt.push_back(i+1);
            cnt = 0;
        }
    }
    print(ans);
    printa(tt, K-1);


}
