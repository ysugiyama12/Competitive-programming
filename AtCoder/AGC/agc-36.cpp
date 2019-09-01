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
    ll S;
    cin >> S;
    ll x1,y1,x2,y2,x3,y3;
    x1 = 0, y1 = 0;
    if(S == 1e18){
        x2 = 1e9;
        y2 = 0;
        x3 = 0;
        y3 = 1e9;
    }else{
        x2 = 1e9;
        y2 = 1;
        x3 = 1e9 - (S % (ll)1e9);
        y3 = (S + x3) / (ll)1e9;
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
    
}