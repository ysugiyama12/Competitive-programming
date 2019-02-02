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
    ll xst, yst,xa, ya, xb, yb, xe, ye;
    cin >> xst >> yst >> xa >> ya >> xb >> yb >> xe >> ye;
    ll dx = abs(xa - xst);
    ll dy = abs(ya - yst);
    cout << xa << "," << 100 << "," << 300 << "," << 300 << "," << ya << "," << 100 << "," << 300 << "," << 300 << ",0,0,0" << endl;
    // cout << xa << "," << 0 << "," << 0 << "," << 0 << "," << ya << "," << 0 << "," << 0 << "," << 0 << ",2,0,0" << endl;
    // cout << xb+3 << "," << 100 << "," << 300 << "," << 300 << "," << yb+3 << "," << 100 << "," << 300 << "," << 300 << ",0,0,0" << endl;
    // cout << xb+3 << "," << 0 << "," << 0 << "," << 0 << "," << yb+3 << "," << 0 << "," << 0 << "," << 0 << ",0,2,0" << endl;
    // cout << xe << "," << 100 << "," << 300 << "," << 300 << "," << ye << "," << 100 << "," << 300 << "," << 300 << ",0,0,0" << endl;
    // cout << xe << "," << 0 << "," << 0 << "," << 0 << "," << ye << "," << 0 << "," << 0 << "," << 0 << ",0,0,4" << endl;
    // double V = 3.141593 * 51 * 51 * 44 / 3;


}
