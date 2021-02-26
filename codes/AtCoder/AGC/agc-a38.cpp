/*** author: yuji9511 ***/
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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W,A,B;
    cin >> H >> W >> A >> B;
    ll ans[1010][1010];
    rep(i,0,H){
        rep(j,0,W){
            if(i < B){
                ans[i][j] = 0;
            }else{
                ans[i][j] = 1;
            }
        }
    }
    rep(j,0,W){
        rep(i,0,H){
            if(j < A){
                if(ans[i][j] == 1){
                    ans[i][j] = 0;
                }else{
                    ans[i][j] = 1;
                }
            }
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            cout << ans[i][j];
        }
        cout << endl;
    }
    
    
}