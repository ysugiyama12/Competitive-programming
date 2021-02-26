#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,C;
    cin >> N >> C;
    ll D[40][40];
    rep(i,0,C){
        rep(j,0,C){
            cin >> D[i][j];
        }
    }
    ll c[510][510];
    rep(i,0,N){
        rep(j,0,N){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    ll ans = INF;
    ll iwakan[35][3] = {};
    rep(i,0,C){
        rep(j,0,3){
            ll val = 0;
            rep(y,0,N){
                rep(x,0,N){
                    if((x+y) % 3 == j){
                        val += D[c[y][x]][i];
                    }
                }
            }
            iwakan[i][j] = val;
        }
    }
    // rep(i,0,C){
    //     rep(j,0,3){
    //         cout << iwakan[i][j] << " \n"[j == 2];
    //     }
    // }

    rep(i,0,C){
        rep(j,0,C){
            rep(k,0,C){
                if(i == j || j == k || k == i) continue;
                ll tt = iwakan[i][0] + iwakan[j][1] + iwakan[k][2];
                ans = min(ans, tt);
            }
        }
    }
    print(ans);

    
}