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
    ll a[1000010];
    cin >> N >> M;
    rep(i,0,N) cin >> a[i];
    sort(a, a+N);
    printa(a,N);
    ll lv = 0, rv = (N+3)/3;
    vector<ll> v;
    ll cnt = 1;
    rep(i,1,N){
        if(a[i] != a[i-1]){
            v.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    v.push_back(cnt);
    printa(v, v.size());
    // while(rv - lv > 1){

    // }
}
