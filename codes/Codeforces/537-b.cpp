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
    ll N,K,M;
    double A[100010];
    cin >> N >> K >> M;
    rep(i,0,N) cin >> A[i];
    sort(A,A+N);
    double ans = 0;
    double sum[100010] = {};
    rep(i,0,N) sum[i+1] = sum[i] + A[i];
    rep(i,0,M+1){
        if(i >= N) continue;
        double v = sum[N] - sum[i];
        double v2 = M - i;
        v += min(v2, (double)K*(N-i));
        v /= (double)(N-i);
        ans = max(ans, v);
    }
    cout << setprecision(10) << ans << endl;




}
