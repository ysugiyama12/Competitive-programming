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
    ll a[7010], b[7010];
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];
    ll ans = 0;
    ll tt[7010] = {};
    rep(i,0,N){
        bool ok = false;
        bool valid[7010] = {};
        valid[i] = true;
        rep(j,0,N){
            if(i == j) continue;
            if(a[i] == a[j]){
                ok = true;
                valid[j] = true;
            }else{
                if((a[i]|a[j]) <= a[i]){
                    valid[j] = true;
                }
            }
        }
        if(ok){
            rep(j,0,N){
                if(valid[j]) tt[j]++;
            }
        }

    }
    rep(i,0,N){
        if(tt[i] > 0) ans += b[i];
    }
    print(ans);
}