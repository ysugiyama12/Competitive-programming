#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
const ll max_N = 100000;
ll fac[max_N + 10], facinv[max_N + 10];

ll power(ll x, ll n){ // xのn乗 % MOD
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1) res = res * x % MOD;
    return res;
}

ll nck(ll n, ll k){
    if(k == 0 || n == k) return 1;
    return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
}

ll npk(ll n, ll k){
    if(k == 0 || n == k) return 1;
    return fac[n] * facinv[n-k] % MOD;
}

void comb_setup(){
    fac[0] = 1; fac[1] = 1;
    rep(i,2,max_N+1) fac[i] = (fac[i-1] * i) % MOD;
    rep(i,0,max_N+1) facinv[i] = power(fac[i], MOD - 2);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    comb_setup();
    ll N;
    ll t[10010];
    cin >> N;
    rep(i,0,N){
        cin >> t[i];
    }
    sort(t, t+N);
    ll sum = 0;
    ll ans = 0;
    ll cnt = 1;
    map<ll,ll> mp;
    rep(i,0,N){
        mp[t[i]]++;
        sum += t[i];
        ans += sum;
    }
    for(auto &e: mp){
        cnt *= fac[e.second];
        cnt %= MOD;
    }
    print(ans);
    print(cnt);
}
