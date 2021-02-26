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
ll a[150010];
ll cnt[150010] = {};
ll ans[150010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    
    rep(i,0,N) cin >> a[i];
    sort(a, a+N);
    
    rep(i,0,N) cnt[a[i]]++;
    vector<ll> v;
    ll ans = 0;
    lpair start, end;
    rep(i,2,150001){
        if(cnt[i])
    }
    
    // rep(i,1,150001){
    //     if(cnt[i] == 1){
    //         ans[i]++;
    //     }else if(cnt[i] >= 3){
    //         ans[i-1]++;
    //         ans[i]++;
    //         ans[i+1]++;
    //     }else if(cnt[i] == 2){
    //         ans[i]++;
    //     }
    // }
    // rep(i,1,150001){
    //     if(cnt[i] == 2){
    //         if(i == 1){
    //             if(ans[i+1] == 0) ans[i+1]++;
    //         }else{
    //             if(ans[i-1] == 0){
    //                 ans[i-1]++;
    //             }else if(ans[i+1] == 0){
    //                 ans[i+1]++;
    //             }
    //         }
    //     }
    // }
    ll res = 0;
    rep(i,1,150001){
        if(ans[i] > 0) res++;
    }
    print(res);

    
}