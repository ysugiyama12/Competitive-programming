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
    ll x,y,z;
    cin >> x >> y >> z;
    ll a,b,c;
    cin >> a >> b >> c;
    a -= x;
    if(a < 0){
        print("NO");
        return 0;
    }
    if(b >= y){
        b -= y;
    }else{
        a -= (y - b);
        b = 0;
    }
    if(a < 0){
        print("NO");
        return 0;
    }
    if(c + a + b >= z){
        print("YES");
    }else{
        print("NO");
    }
}
