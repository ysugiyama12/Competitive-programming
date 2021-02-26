#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl;
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;

typedef long long ll;
using namespace std;

static const int MOD = 998244353;
static const int MAX_N = 300000;
vector<ll> fac(MAX_N+1);
vector<ll> facinv(MAX_N+1);

ll power(ll x, ll n){ //pow(x,n) % MOD
    if (n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1){ res = res * x % MOD; }
    return res;
}

ll ncr(ll n, ll k){ //Combination(n, k)
    if (k == 0 || n ==k){ return 1;}
    return (((fac[n] * facinv[k]) % MOD) * facinv[n-k]) % MOD;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N,A,B,K;
    cin >> N >> A >> B >> K;

    ll ans = 0;
    vector<ll> num_b(N+1);
    rep(i,0,N+1){
        if((K - A*i)%B == 0 && K - A*i >= 0){
            num_b[i] = (K-A*i)/B;
        }else{
            num_b[i] = -1;
        }
    }

    fac[0] = 0;
    fac[1] = 1;
    rep(i,2,N+1){
        fac[i] = (fac[i-1] * i) % MOD;
    }
    rep(i,0,N+1){
        facinv[i] = power(fac[i], MOD-2);
    }

    rep(i,0,N+1){
        if(i <= N && num_b[i] <= N && num_b[i] >= 0){
            ans += (ncr(N,i) * ncr(N, num_b[i]))%MOD;
            ans %= MOD;
        }

    }
    ll result = ans % MOD;

    print(result);

}
