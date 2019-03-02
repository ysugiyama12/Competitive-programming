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
    ll N;
    ll A[200010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    ll sum_even[200010] = {}, sum_odd[200010] = {};
    rep(i,0,N){
        if(i % 2 == 0){
            sum_even[i+1] = sum_even[i] + A[i];
            sum_odd[i+1] = sum_odd[i];
        }else{
            sum_odd[i+1] = sum_odd[i] + A[i];
            sum_even[i+1] = sum_even[i];
        }
    }
    rep(i,0,N){
        if(sum_even[i] + sum_odd[N] - sum_odd[i+1] == sum_odd[i] + sum_even[N] - sum_even[i+1]){
            ans++;
        }
    }
    print(ans);
}
