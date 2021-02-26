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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
ll dist[1010][1010];
ll is_visit[1010][1010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W;
    cin >> H >> W;
    char c[1010][1010];
    rep(i,0,H){
        rep(j,0,W){
            cin >> c[i][j];
        }
    }
    queue<ll> qq;
    rep(i,0,H){
        rep(j,0,W){
            if(c[i][j] == '#') qq.push(i*W+j);
            if(c[i][j] == '#'){
                dist[i][j] = 0;
            }else{
                dist[i][j] = INF;
            }
        }
    }
    ll dh[4] = {0,0,1,-1};
    ll dw[4] = {1,-1,0,0};

    while(not qq.empty()){
        ll p = qq.front();
        qq.pop();
        ll i = p/W;
        ll j = p%W;
        // if(dist[i][j] != INF) continue;
        rep(k,0,4){
            ll hh = i + dh[k];
            ll ww = j + dw[k];
            if(hh >= 0 && hh < H && ww >= 0 && ww < W){
                if(dist[hh][ww] == INF){
                    dist[hh][ww] = dist[i][j] + 1;
                    qq.push(hh*W+ww);
                }
            }

        }

    }
    ll ans = 0;
    rep(i,0,H){
        rep(j,0,W){
            ans = max(ans, dist[i][j]);
        }
    }
    // rep(i,0,H){
    //     rep(j,0,W){
    //         cout << dist[i][j] << " \n"[j==W-1];
    //     }
    // }
    print(ans);


}