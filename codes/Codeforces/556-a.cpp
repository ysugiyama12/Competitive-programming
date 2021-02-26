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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,R;
    cin >> N >> M >> R;
    ll S[35], B[35];
    rep(i,0,N) cin >> S[i];
    rep(i,0,M) cin >> B[i];
    ll tt = INF, vv = 0;
    rep(i,0,N) tt = min(tt, S[i]);
    rep(i,0,M) vv = max(vv, B[i]);
    if(tt > vv){
        print(R);
    }else{
        ll v = R / tt;
        ll amari = R % tt;
        v = v * vv;
        ll ans = amari + v;
        print(ans);
    }
    
}