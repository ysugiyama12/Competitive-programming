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
    ll b,k;
    ll a[100010];
    cin >> b >> k;
    rep(i,0,k) cin >> a[i];
    if(b % 2 == 0){
        if(a[k-1] % 2 == 0){
            print("even");
        }else{
            print("odd");
        }
        return 0;
    }
    ll cnt = 0;
    rep(i,0,k){
        if(a[i] % 2 != 0) cnt++;
    }
    // print(cnt);
    if(cnt % 2 == 0){
        print("even");
    }else{
        print("odd");
    }
}
