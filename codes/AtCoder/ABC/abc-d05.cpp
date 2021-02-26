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
    ll N;
    cin >> N;
    ll D[55][55];
    rep(i,0,N){
        rep(j,0,N){
            cin >> D[i][j];
        }
    }
    ll Q;
    cin >> Q;
    ll imos[55][55] = {};
    rep(i,0,N){
        rep(j,0,N){
            imos[i+1][j+1] = D[i][j];
        }
    }
    rep(i,0,N+1){
        rep(j,0,N+1){
            imos[i][j+1] += imos[i][j];
        }
    }
    rep(j,0,N+1){
        rep(i,0,N+1){
            imos[i+1][j] += imos[i][j];
        }
    }
    ll max_val[2510] = {};
    rep(lv,0,N){
        rep(rv,lv,N){
            rep(uv,0,N){
                rep(dv,uv,N){
                    ll num = (rv - lv + 1) * (dv - uv + 1);
                    ll val = imos[rv+1][dv+1] - imos[lv][dv+1] - imos[rv+1][uv] + imos[lv][uv];
                    max_val[num] = max(max_val[num], val);
                }
            }
        }
    }
    rep(i,2,N*N+1){
        max_val[i] = max(max_val[i], max_val[i-1]);
    }

    while(Q--){
        ll P;
        cin >> P;
        print(max_val[P]);
    }

}