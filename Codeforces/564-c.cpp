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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[200010], b[200010];
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];
    map<ll,ll> mp_a;
    rep(i,0,N) mp_a[a[i]]++;
    ll pos[200010] = {};
    rep(i,0,N){
        pos[b[i]] = i+1;
    }
    ll p1 = -1;
    rep(i,0,N){
        if(b[i] == 1){
            p1 = i;
            break;
        }
    }
    //from start 0
    if(p1 != -1){
        bool ok = true;
        rep(i,p1,N){
            if(b[i] != i - p1 + 1) ok = false;
        }
        if(ok){
            ll v = N - p1;
            rep(n,v+1,N+1){
                if(mp_a[n]){
                }else if(pos[n] <= n - v - 1){
                }else{
                    ok = false;
                }
            }
            if(ok){
                print(N - v);
                return 0;
            }
        }
    }
    ll d[200010] = {};
    rep(i,1,N+1){
        if(mp_a[i] == 1){
            d[i] = 0;
        }else{
            d[i] = pos[i];
        }
    }
    rep(i,1,N+1){
        d[i] -= (i-1);
        d[i] = max(0LL, d[i]);
    }
    ll max_val = 0;
    rep(i,1,N+1){
        max_val = max(max_val, d[i]);
    }
    ll ans = max_val + N;
    print(ans);




}