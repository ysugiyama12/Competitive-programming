#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll a[100010];
    cin >> N;
    rep(i,0,N) cin >> a[i];
    ll is_used[100010] = {};
    bool ok = true;
    rrep(bit,31,0){
        ll cnt = 0;
        rep(i,0,N){
            if((a[i]>>bit) & 1) cnt++;
        }
        if(cnt % 2 == 0) continue;
        // print(bit);
        bool flg = true;
        rep(i,0,N){
            if(a[i] % (1LL<<(bit+1)) == (1LL<<(bit)) && is_used[i] == 0){
                is_used[i] = 1;
                // print2(bit,i);
                a[i]--;
                flg = false;
                break;
            }
        }
        if(flg){
            ok = false;
        }
    }
    if(!ok){
        print(-1);
    }else{
        ll ans = 0;
        rep(i,0,N){
            if(is_used[i] == 1) ans++;
        }
        print(ans);
    }
    //010
    //011
    //100

    //001
    //010
    //011
    
}
