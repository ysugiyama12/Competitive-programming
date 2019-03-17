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
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} //最大公約数
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;} //最小公倍数

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll S[110], T[110];
    cin >> N;
    rep(i,0,N) cin >> S[i];
    rep(i,0,N) cin >> T[i];
    ll diff[110] = {};
    rep(i,0,N){
        diff[i] = S[i] - T[i];
    }
    ll v = diff[0];
    rep(i,0,N){
        if(i == 0){
            cout << 1 << " " << 1 << endl;
        }else{
            ll vv = gcd(diff[0], diff[i]);
            cout << diff[i]/vv << " " << diff[0]/vv << endl;
        }
    }
}
