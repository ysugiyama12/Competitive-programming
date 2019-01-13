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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    ll l[510], r[510], d[510];
    cin >> Q;
    rep(i,0,Q){
        cin >> l[i] >> r[i] >> d[i];
    }
    rep(i,0,Q){
        if(d[i] >= l[i] && d[i] <= r[i]){
            ll v = r[i] % d[i];
            r[i] += (d[i] - v);
            print(r[i]);
        }else{
            print(d[i]);
        }
    }


}
