#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    ll A[100010];
    cin >> K;
    rep(i,0,K){
        cin >> A[i];
    }
    ll lv = -1, rv = INF;
    while(rv - lv > 1){
        ll mid = (rv + lv)/2;
        ll v = mid;
        rep(i,0,K){
            v -= (v % A[i]);
            if(v < 0) v = 0;
        }
        
        if(v >= 2){
            rv = mid;
        }else{
            lv = mid;
        }
    }
    ll l1 = lv, r1 = rv;
    // print2(lv,rv);
    lv = -1, rv = INF;
    while(rv - lv > 1){
        ll mid = (rv + lv)/2;
        ll v = mid;
        rep(i,0,K){
            v -= (v % A[i]);
            if(v < 0) v = 0;
        }
        
        if(v >= 3){
            rv = mid;
        }else{
            lv = mid;
        }
    }
    ll l2 = lv, r2 = rv;
    if(r1 > l2){
        print("-1");
    }else{
        cout << r1 << " " << l2 << endl;
    }
    
    // bool ok = true;
    // rrep(i, K-2, 0){
    //     if(A[i] >= 2 * A[i+1]){
    //         ok = false;
    //     }
    // }
    // if(!ok){
    //     print("-1");
    //     return 0;
    // }
    // ll v1 = A[0];
    // ll v2 = A[1];
    // ll amari = v2 % v1;
    // if(amari == 0) amari = v1;
    // ll ans1 = v2 + (v1 - amari);
    // v2 *= 2;
    // amari = v2 % v1;
    // if(amari == 0) amari = v1;
    // ll ans2 = v2 + (v1 - amari) - 1;
    // cout << ans1 << " " << ans2 << endl;

    

}
