#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} //最大公約数
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;} //最小公倍数

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Z;
    cin >> N >> Z;
    ll a[100010];
    rep(i,0,N){
        cin >> a[i];
    }
    ll v[100010] = {};
    rep(i,0,N){
        v[i] = gcd(Z, a[i]);
    }
    ll ans = v[0];
    rep(i,1,N){
        ans = lcm(ans,v[i]);
    }
    print(ans);


    
}
