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
    ll a[110];
    rep(i,0,N) cin >> a[i];
    sort(a, a+N);
    ll ans = 0;
    ll check[110] = {};
    rep(i,0,N){
        if(check[i] == 1) continue;
        check[i] = 1;
        ans++;
        rep(j,i+1,N){
            if(check[j] == 0 && a[j] % a[i] == 0){
                check[j] = 1;
            }
        }
    }
    print(ans);
    
}