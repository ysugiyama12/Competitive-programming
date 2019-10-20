/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,K;
    cin >> N >> M >> K;
    ll x[100010], y[100010];
    vector<ll> vx[100010], vy[100010];
    rep(i,0,K){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        vx[x[i]].push_back(y[i]);
        vy[y[i]].push_back(x[i]);
    }
    rep(i,0,N) sort(vx[i].begin(), vx[i].end());
    rep(i,0,M) sort(vy[i].begin(), vy[i].end());

    ll limits[4] = {};
    limits[0] = -1; limits[1] = M; limits[2] = N; limits[3] = -1;
    ll idx = 0;
    ll curX = 0, curY = 0;
    vector<lpair> lp;
    lp.push_back({0,0});
    while(1){

        if(idx % 4 == 0){
            ll p = lower_bound(vx[curX].begin(), vx[curX].end(), curY) - vx[curX].begin();
            ll nxt = -1;
            if(p == vx[curX].size()){
                nxt = limits[(idx+1)%4]-1;
            }else{
                nxt = min(vx[curX][p]-1, limits[(idx+1)%4]-1);
            }
            if(nxt == curY) break;
            curY = nxt;
            limits[idx%4] = curX;
        }else if(idx % 4 == 1){
            ll p = lower_bound(vy[curY].begin(), vy[curY].end(), curX) - vy[curY].begin();
            ll nxt = -1;
            if(p == vy[curY].size()){
                nxt = limits[(idx+1) % 4]-1;
            }else{
                nxt = min(vy[curY][p]-1, limits[(idx+1) % 4]-1);
            }
            if(nxt == curX) break;
            curX = nxt;
            limits[idx%4] = curY;
        }else if(idx % 4 == 2){
            ll p = lower_bound(vx[curX].begin(), vx[curX].end(), curY) - vx[curX].begin();
            ll nxt = -1;
            if(p == 0){
                nxt = limits[(idx+1)%4] + 1;
            }else{
                nxt = max(vx[curX][p-1] + 1, nxt = limits[(idx+1)%4] + 1);
            }
            if(nxt == curY) break;
            curY = nxt;
            limits[idx%4] = curX;
        }else{
            ll p = lower_bound(vy[curY].begin(), vy[curY].end(), curX) - vy[curY].begin();
            ll nxt = -1;
            if(p == 0){
                nxt = limits[(idx+1) % 4]+1;
                // print(idx, limits[0]);
            }else{
                nxt = max(vy[curY][p-1]+1, limits[(idx+1) % 4]+1);
            }
            if(nxt == curX) break;
            curX = nxt;
            limits[idx%4] = curY;  
        }
        idx++;
        lp.push_back({curX, curY});
    }
    ll ans = 0;
    rep(i,0,lp.size()-1){
        ans += abs(lp[i].first - lp[i+1].first) + abs(lp[i].second - lp[i+1].second);
    }
    ans++;
    if(ans == N*M - K){
        print("Yes");
    }else{
        print("No");
    }
    

    
 
}