#include <bits/stdc++.h>
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
    ll N,M;
    cin >> N >> M;
    ll A[200010];
    rep(i,0,N) cin >> A[i];
    sort(A, A+N, greater<ll>());
    ll sum = 0;
    rep(i,0,N) sum += A[i];
    if(M > sum){
        print(-1);
        return 0;
    }
    ll lv = 0, rv = N+1;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;

        ll ans = 0;
        rep(i,0,N){
            ll v = i / mid;
            ans += max(0LL, A[i] - v);
        }

        if(ans >= M){
            rv = mid;
        }else{
            lv = mid;
        }
    }
    print(rv);
}
