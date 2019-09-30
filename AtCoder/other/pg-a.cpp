/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
#define print(x) cout << (x) << endl;
#define print2(x, y) cout << (x) << " " << (y) << endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll A[200010];
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    rep(i,0,N){
        if(A[i] > K) ans += (A[i] - K);
    }
    print(ans);
    
}

