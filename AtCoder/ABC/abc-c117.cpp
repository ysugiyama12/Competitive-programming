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
    ll N,M;
    cin >> N >> M;
    ll X[100010];
    rep(i,0,M) cin >> X[i];
    if(N >= M){
        print(0);
        return 0;
    }
    sort(X, X+M);
    vector<ll> diff;
    rep(i,0,M-1){
        diff.push_back(X[i+1] - X[i]);
    }
    sort(diff.begin(), diff.end());
    ll ans = 0;
    rep(i,0,M-N){
        ans += diff[i];
    }
    print(ans);



}
