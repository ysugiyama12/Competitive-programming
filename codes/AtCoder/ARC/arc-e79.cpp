#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[55];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    while(1){
        bool ok = true;
        rep(i,0,N){
            if(A[i] >= N) ok = false;
        }
        if(ok) break;
        ll sum = 0;
        rep(i,0,N){
            sum += A[i] / N;
        }
        ans += sum;
        rep(i,0,N){
            ll v = A[i] / N;
            A[i] += (sum - v) - v * N;
        }
    }
    print(ans);
}
