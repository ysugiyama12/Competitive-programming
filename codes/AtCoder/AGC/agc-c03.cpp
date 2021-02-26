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
    ll A[100010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    ll B[100010];
    memcpy(B, A, sizeof(A));
    sort(B, B+N);
    map<ll,ll> mp;
    rep(i,0,N){
        mp[B[i]] = i;
    }
    rep(i,0,N){
        A[i] = mp[A[i]];
    }
    // printa(A,N);
    ll ans = 0;
    rep(i,0,N){
        if(abs(A[i] - i) % 2 != 0){
            ans++;
        }
    }
    ans /= 2;
    print(ans);
}
