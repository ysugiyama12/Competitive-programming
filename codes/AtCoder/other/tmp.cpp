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
ll ans[300010][4] = {};
ll a[510][510];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W;
    cin >> H >> W;
    rep(i,0,H){
        rep(j,0,W){
            cin >> a[i][j];
        }
    }
    ll cnt = 0;
    rep(i,0,H){
        rep(j,0,W-1){
            if(a[i][j] % 2 == 1){
                ans[cnt][0] = i+1; ans[cnt][1] = j+1; ans[cnt][2] = i+1; ans[cnt][3] = j+2;
                a[i][j]--;
                a[i][j+1]++;
                cnt++;
            }
        }
    }
    rep(j,0,W){
        rep(i,0,H-1){
            if(a[i][j] % 2 == 1){
                ans[cnt][0] = i+1; ans[cnt][1] = j+1; ans[cnt][2] = i+2; ans[cnt][3] = j+1;
                a[i][j]--;
                a[i+1][j]++;
                cnt++;
            }

        }
    }
    print(cnt);
    // rep(i,0,cnt){
    //     rep(j,0,4){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0;i < cnt;i++) {
        rep(j,0,4){
            cout << ans[i][j] << " \n"[j == 3];
        }
    }
}
