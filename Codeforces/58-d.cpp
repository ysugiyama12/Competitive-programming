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
char q[500010];
ll x[500010], y[500010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x_min = -1, y_min = -1;
    rep(i,0,N){
        cin >> q[i] >> x[i] >> y[i];
        if(q[i] == '+'){
            if(x_min == -1){
                x_min = min(x[i], y[i]);
            }else{
                x_min = max(x_min, min(x[i], y[i]));
            }
            if(y_min == -1){
                y_min = max(x[i], y[i]);
            }else{
                y_min = max(y_min, max(x[i], y[i]));
            }
        }else{
            ll v1 = min(x[i], y[i]);
            ll v2 = max(x[i], y[i]);
            if(x_min <= v1 && y_min <= v2){
                print("YES");
            }else{
                print("NO");
            }
        }
    }
}
