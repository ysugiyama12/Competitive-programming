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
ll ans = 0;
ll d[55] = {};
ll v[55] = {};
void check(ll n, ll x){
    x--;
    if(x == 0) return;
    if(x >= v[n-1]){
        ans += d[n-1];
        x -= v[n-1];
    }else{
        check(n-1, x);
        return;
    }
    if(x >= 1){
        ans++;
        x--;
    }else{
        return;
    }
    if(x == 0) return;
    if(x >= v[n-1]){
        ans += d[n-1];
        x -= v[n-1];
    }else{
        check(n-1, x);
        return;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X;
    cin >> N >> X;
    d[0] = 1;
    rep(i,1,51){
        d[i] = 2 * d[i-1] + 1;
    }
    v[0] = 1;
    rep(i,1,51){
        v[i] = 2 * v[i-1] + 3;
    }
    ll x = X;
    check(N, X);
    print(ans);
}
