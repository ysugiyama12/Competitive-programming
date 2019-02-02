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
inline bool isPrime(ll x){ //素数かどうか判定
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(ll i=3;i<=sqrt(x)+1;i+=2) if(x%i==0) return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    n = n*(n+1)/2;
    if(isPrime(n)){
        print("WANWAN");
    }else{
        print("BOWWOW");
    }
}
