#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[300010];
    ll M;
    ll Q[300010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    cin >> M;
    rep(i,0,M) cin >> Q[i];
    sort(A, A+N);
    ll sum[300010] = {};
    rep(i,0,N) sum[i+1] = sum[i] + A[i];
    rep(i,0,M){
        print(sum[N] - A[N-Q[i]]);
    }

}