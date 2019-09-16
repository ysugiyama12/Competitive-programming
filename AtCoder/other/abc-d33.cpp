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
    ll x[2010], y[2010];
    rep(i,0,N) cin >> x[i] >> y[i];
    ll ei = 0, tyoku = 0, don = 0;
    const double pi = acos(-1);
    const double eps = 1e-10;
    rep(i,0,N){
        vector<double> v;
        rep(j,0,N){
            if(i == j) continue;
            v.push_back(atan2(y[j] - y[i], x[j] - x[i])); // arctan(y/x)
        }
        sort(v.begin(), v.end());
        rep(j,0,N-1) v.push_back(v[j] + 2*pi); //もう1周
        rep(j,0,N-1){
            tyoku += upper_bound(v.begin(), v.end(), v[j] + pi/2 + eps) - upper_bound(v.begin(), v.end(), v[j] + pi/2 - eps);
            don += upper_bound(v.begin(), v.end(), v[j] + pi) - upper_bound(v.begin(), v.end(), v[j] + pi/2 + eps);
        }
    }
    ei = N*(N-1)*(N-2)/6 - tyoku - don;
    cout << ei << " " << tyoku << " " << don << endl;
    
}