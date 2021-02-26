#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll x[110], y[110];
    cin >> N;
    rep(i,0,N) cin >> x[i] >> y[i];
    ll ans = 0;
    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,N){
                if(i < j && j < k){
                    ll x1 = x[j] - x[i];
                    ll y1 = y[j] - y[i];
                    ll x2 = x[k] - x[i];
                    ll y2 = y[k] - y[i];
                    ll S = abs(x1*y2-y1*x2);
                    if(S % 2 == 0 && S != 0) ans++;
                }
            }
        }
    }
    print(ans);
}
