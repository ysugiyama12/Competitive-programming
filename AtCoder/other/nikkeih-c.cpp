#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W,K;
    cin >> H >> W >> K;
    ll R[100010], C[100010];
    rep(i,0,K){
        cin >> R[i] >> C[i];
        R[i]--; C[i]--;
    }
    ll mid_H = 0, mid_W = 0;
    ll num = H*W - K;
    map<ll,ll> mp_H, mp_W;
    rep(i,0,H) mp_H[i] = W;
    rep(i,0,W) mp_W[i] = H;
    rep(i,0,K){
        mp_H[R[i]]--;
        mp_W[C[i]]--;
    }
    ll mid = (num+1)/2;
    ll idx = 0;
    rep(i,0,H){
        idx += mp_H[i];
        if(idx >= mid){
            mid_H = i;
            break;
        }
    }
    idx = 0;
    rep(i,0,W){
        idx += mp_W[i];
        if(idx >= mid){
            mid_W = i;
            break;
        }
    }
    ll ans = 0;
    rep(i,0,H){
        ans += abs(mid_H - i) * mp_H[i];
    }
    rep(i,0,W){
        ans += abs(mid_W - i) * mp_W[i];
    }
    print(ans);
}
