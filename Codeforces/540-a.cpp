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
    ll q;
    cin >> q;
    ll n[510], a[510], b[510];
    rep(i,0,q){
        cin >> n[i] >> a[i] >> b[i];
    }
    rep(i,0,q){
        if(n[i] % 2 == 0){
            if(a[i] * 2 <= b[i]){
                print(a[i]*n[i]);
            }else{
                print(b[i]*n[i]/2);
            }

        }else{
            ll ans = 0;
            if(a[i]*2 <= b[i]){
                ans += (n[i]-1)* a[i];
            }else{
                ans += (n[i]-1) * b[i]/2;
            }
            ans += a[i];
            print(ans);
        }
    }
}
