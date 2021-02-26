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
    ll lv;
    ll rv;
} Q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll P[100010] = {};
    rep(i,0,N) cin >> P[i];
    vector<Q> arr(100010);
    arr[0] = (Q){-1, 1};
    arr[1] = (Q){0, 2};
    ll pos[100010] = {};
    rep(i,0,N){
        arr[i+2] = (Q){i+1, i+3};
        pos[P[i]] = i+2;
    }
    arr[N+2] = (Q){N+1, N+3};
    arr[N+3] = (Q){N+2, N+4};

    ll ans = 0;
    rep(n,1,N){
        ll p = pos[n];
        ll lv = arr[p].lv;
        ll rv = arr[p].rv;
        if(lv != 1){
            ans += n * (lv - arr[lv].lv) * (rv - p);
        }
        if(rv != N+2){
            ans += n * (arr[rv].rv - rv) * (p - lv);
        }

        arr[lv].rv = arr[p].rv;
        arr[rv].lv = arr[p].lv;
    }
    print(ans);



    
}