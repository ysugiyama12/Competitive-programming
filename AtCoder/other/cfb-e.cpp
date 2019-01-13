#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll gcd( ll m, ll n )
{
    if (n == 0){
        return m;
    }else{
        return gcd(n, m % n);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll val = 1;
    rep(i,2,N+1){
        ll vg = gcd(val, i);
        val = val /vg;
        val *= i;
        val %= MOD;
    }
    print(val);
    ll num[210] = {};
    rep(i,1,N+1){
        num[i] = val/i;
    }
    rep(i,N+1, 2*N+1){
        num[i] = - num[i - N];
    }
    printa(num, 2*N+1);

}
