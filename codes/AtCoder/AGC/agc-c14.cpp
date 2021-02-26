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
typedef struct {
    ll h;
    ll w;
    ll d;
} P;
ll imos[810][810] = {};
bool visit[810][810] = {};
int dist[810][810] = {};
string S[810];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W,K;
    cin >> H >> W >> K;
    rep(i,0,H) cin >> S[i];

    queue<P> que;
    ll dh[4] = {0,0,1,-1};
    ll dw[4] = {1,-1,0,0};
    rep(i,0,H){
        rep(j,0,W){
            dist[i][j] = -1;
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == 'S'){
                que.push((P){i, j, 0});
            }
        }
    }

    while(not que.empty()){
        P p1 = que.front();
        que.pop();
        if(visit[p1.h][p1.w]) continue;
        visit[p1.h][p1.w] = true;
        dist[p1.h][p1.w] = p1.d;
        rep(k,0,4){
            ll ah = p1.h + dh[k];
            ll aw = p1.w + dw[k];
            if(ah >= 0 && ah < H && aw >= 0 && aw < W){
                if((not visit[ah][aw]) && S[ah][aw] == '.'){
                    que.push((P){ah, aw, p1.d+1});
                }
            }
        }
    }

    ll lv = 0, rv = H*W;
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == '#') imos[i+1][j+1]++;
        }
    }
    rep(i,0,H+1){
        rep(j,0,W+1){
            imos[i][j+1] += imos[i][j];
        }
    }
    rep(j,0,W+1){
        rep(i,0,H+1){
            imos[i+1][j] += imos[i][j];
        } 
    }
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        bool ok = false;
        rep(i,0,H){
            rep(j,0,W){
                if(dist[i][j] >= 0){
                    if(dist[i][j] <= K){
                        ll kabe = 0, len = 0;
                        // up
                        if(i <= K * (mid-1)) ok = true;
                        if(H-i-1 <= K * (mid-1)) ok = true;
                        if(j <= K*(mid-1)) ok = true;
                        if(W-j-1 <= K*(mid-1)) ok = true;
                    }
                }
            }
        }

        if(ok){
            rv = mid;
        }else{
            lv = mid;
        }
    }
    print(rv);


}