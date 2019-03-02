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
    ll N,K;
    ll A[100010];
    cin >> N >> K;
    rep(i,0,N) cin >> A[i];



    //以下嘘解法
    sort(A, A+N);
    ll ans = 0;
    rrep(bit, 41, 0){
        // print2("bit",bit);
        ll cnt = 0;
        rep(i,0,N){
            if(A[i] < (1LL<<bit)) continue;
            if((A[i]>>bit) & 1) cnt++;
        }
        if(cnt <= N/2){
            if(ans + (1LL<<bit) <= K){
                ans += (1LL<<bit);
            }
        }
        // print(ans);
    }
    ll v = 0;
    rep(i,0,N){
        v += (A[i]^ans);
    }
    print(v);

}
