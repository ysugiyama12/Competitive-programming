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
    ll idx;
    ll num;
    ll lv;
    ll rv;
} Q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll P[100010];
    rep(i,0,N) cin >> P[i];
    vector<Q> v(100010);
    ll pos[100010] = {};
    rep(i,0,N){
        ll lv = -1, rv = -1;
        if(i != 0) lv = i-1;
        if(i != N-1) rv = i+1;
        v[i] = (Q){i, P[i], lv, rv};
        pos[P[i]] = i; 
    }
    ll ans = 0;
    rep(n,1,N){
        ll lv = -1, rv = -1;
        ll lv2 = -1, rv2 = -1;
        ll cur = pos[n];
        lv = v[cur].lv;
        rv = v[cur].rv;
        if(lv != -1){
            lv2 = v[lv].lv;
        }
        if(rv != -1){
            rv2 = v[rv].rv;
        }
        if(lv == -1 && rv != -1){
            ll left_val = cur+1;
            ll right_val = 0;
            if(rv2 != -1){
                right_val = rv2 - rv;
            }else{
                right_val = N - rv;
            }
            ans += n * left_val * right_val;
        }else if(lv != -1 && rv == -1){
            ll right_val = N - cur;
            ll left_val = 0;
            if(lv2 != -1){
                left_val = lv - lv2;
            }else{
                left_val = lv+1;
            }
            ans += n * left_val * right_val;
        }else{
            ll left_val = 0;
            if(lv2 != -1){
                left_val = lv - lv2;
            }else{
                left_val = lv+1;
            }
            ll right_ok = rv - cur;
            ans += n * left_val * right_ok;

            ll right_val = 0;
            if(rv2 != -1){
                right_val = rv2 - rv;
            }else{
                right_val = N - rv;
            }
            ll left_ok = cur - lv;
            ans += n * right_val * left_ok;
        }
        if(lv != -1){
            v[lv].rv = v[cur].rv;
        }
        if(rv != -1){
            v[rv].lv = v[cur].lv;
        }
    }
    print(ans);
}