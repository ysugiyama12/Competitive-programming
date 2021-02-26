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
ll imos[5010][5010] = {};
ll calc(ll sx, ll sy, ll gx, ll gy){
    return imos[sx+1][sy+1] - imos[sx+1][gy] - imos[gx][sy+1] + imos[gx][gy];
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll x[100010], y[100010];
    char c[100010];
    rep(i,0,N){
        cin >> x[i] >> y[i] >> c[i];
        if(c[i] == 'B'){
            y[i] += K;
        }
        x[i] %= 2*K;
        y[i] %= 2*K;
    }

    ll ans = 0;
    rep(i,0,N){
        imos[K+x[i]+1][K+y[i]+1]++;
    }

    rep(i,0,5*K+5){
        rep(j,0,5*K+5){
            imos[i][j+1] += imos[i][j];
        }
    }
    rep(j,0,5*K+5){
        rep(i,0,5*K+5){
            imos[i+1][j] += imos[i][j];
        }
    }

    rep(i,0,2*K){
        rep(j,0,2*K){
            ll val = 0;
            ll gx = i+K, gy = j+K;
            if(i >= K){
                gx -= 2*K;
                val += calc(gx+K-1, gy+K-1, gx, gy);
                gx += 2*K;
            }
            if(j >= K){
                gy -= 2*K;
                val += calc(gx+K-1, gy+K-1, gx, gy);
                gy += 2*K;
            }
            val += calc(gx+K-1, gy+K-1, gx, gy);
            gx -= K; gy -= K;
            val += calc(gx+K-1, gy+K-1, gx, gy);
            gx += 2*K;
            val += calc(gx+K-1, gy+K-1, gx, gy);
            gx -= 2*K; gy += 2*K;
            val += calc(gx+K-1, gy+K-1, gx, gy);
            gx += 2*K;
            val += calc(gx+K-1, gy+K-1, gx, gy);
            ans = max(ans, val);
        }
    }
    print(ans);

}
