#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
typedef pair<ll, ll> lpair;
ll power(ll x, ll n){ // xのn乗 % MOD
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1){
        res = res * x % MOD;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll a[200010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    map<ll,ll> mp;
    rep(i,0,N){
        mp[a[i]]++;
    }
    ll cnt = 0;
    ll mode = 0;
    rep(i,0,N){
        if(mp[a[i]] == 1){
            if(mode == 0){
                cnt++;
            }else{
                mode--;
            }
        }else{
            mp[a[i]]--;

        }
    }
    
    // ll sum[200010] = {};
    // rep(i,0,N){
    //     if(mp[a[i]] == 0){
    //         mp[a[i]] = i+1;
    //     }else{
    //         sum[mp[a[i]]]++;
    //         sum[i+2]--;
    //         mp[a[i]] = i+1;
    //     }
    // }
    // printa(sum, N+2);
    // rep(i,0,N+2){
    //     sum[i+1] += sum[i];
    // }
    // ll cnt = 0;
    // bool flg = false;
    // rep(i,1,N+1){
    //     if(sum[i] == 0){
    //         cnt++;
    //         flg = false;
    //     }else{
    //         if(flg == false){
    //             cnt++;
    //             flg = true;
    //         }
    //     }
    // }
    // ll ans = power(2, cnt-1) % MOD;
    // printa(sum, N+2);
    // print(ans);
}
