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
    ll H,W;
    ll C[110][110];
    cin >> H >> W;
    rep(i,0,H){
        rep(j,0,W){
            cin >> C[i][j];
        }
    }
    ll sum[110][110] = {};
    rep(i,0,H){
        rep(j,0,W){
            if((i+j) % 2 == 0){
                sum[i+1][j+1] = C[i][j];
            }else{
                sum[i+1][j+1] = -C[i][j];
            }
        }
    }
    rep(i,0,H+1){
        rep(j,0,W+1){
            sum[i][j+1] += sum[i][j];
        }
    }
    rep(j,0,W+1){
        rep(i,0,H+1){
            sum[i+1][j] += sum[i][j];
        }
    }
    ll ans = 0;
    // rep(i,0,H+2){
    //     rep(j,0,W+2){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    rep(i,0,H){
        rep(j,0,W){
            rep(k,0,H){
                rep(l,0,W){
                    if(i < k || j < l) continue;
                    ll val = sum[i+1][j+1] + sum[k][l] - sum[i+1][l] - sum[k][j+1];
                    ll tt = (i-k+1) * (j-l+1);
                    if(val == 0){
                        ans = max(ans, tt);
                    }
                }
            }
        }
    }
    print(ans);
}
