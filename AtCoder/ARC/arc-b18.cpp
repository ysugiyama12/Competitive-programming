#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    ll A[300010];
    cin >> N >> K;
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    ll diff[300010] = {};
    rep(i,0,N-1){
        if(A[i+1] - A[i] > 0){
            diff[i] = 1;
        }
    }
    ll sum[300010] = {};
    rep(i,0,N-1){
        sum[i+1] = sum[i] + diff[i];
    }
    rep(i,0,N-K+1){
        if(sum[i+K-1] - sum[i] == K-1) ans++;
    }
    print(ans);

}