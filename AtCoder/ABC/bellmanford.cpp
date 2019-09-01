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
    // ABC61-D Score Attack
    ll N,M;
    cin >> N >> M;
    ll a[2010], b[2010], c[2010];
    rep(i,0,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        c[i] *= -1;
    }
    ll dist[1010] = {};
    rep(i,1,N) dist[i] = INF;
    // 更新
    rep(loop,0,N-1){
        rep(i,0,M){
            if(dist[a[i]] == INF) continue;
            if(dist[b[i]] > dist[a[i]] + c[i]){
                dist[b[i]] = dist[a[i]] + c[i];
            }
        }
    }

    bool negative[1010];
    rep(i,0,N) negative[i] = false;
    rep(loop,0,N){
        rep(i,0,M){
            if(dist[a[i]] == INF) continue;
            if(dist[b[i]] > dist[a[i]] + c[i]){
                dist[b[i]] = dist[a[i]] + c[i];
                negative[b[i]] = true;
            }
            if(negative[a[i]]) negative[b[i]] = true;
        }
    }
    
    if(negative[N-1]){
        print("inf");
    }else{
        print(-1 * dist[N-1]);
    }


    
}