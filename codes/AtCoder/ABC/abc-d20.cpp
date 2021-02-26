/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
struct Integer{
public:
    ll gcd(ll a,ll b){return b ? gcd(b, a % b) : a;} //最大公約数
    ll lcm(ll a,ll b){return a / gcd(a, b) * b;} //最小公倍数
    bool isPrime(ll x){
        if(x < 2) return false;
        if(x == 2) return true;
        if(x % 2 == 0) return false;
        for(ll i = 3;i <= sqrt(x) + 1;i += 2) if(x % i == 0) return false;
        return true;
    }
    vector<ll> divisor(ll M){ //約数の全列挙
        vector<ll> dd;
        for(ll i = 1; i * i <= M; i++){
            if(M % i == 0){
                dd.push_back(i);
                if(i * i != M) dd.push_back(M / i);
            }
        }
        sort(dd.begin(), dd.end());
        return dd;
    }
    vector<ll> factor(ll M){ //素因数分解
        vector<ll> dd;
        if(M == 1){
            dd.push_back(1);
            return dd;
        }
        for(ll i = 2; i*i <= M; i++){
            while(M % i == 0){
                dd.push_back(i);
                M /= i;
            }
        }
        if(M != 1) dd.push_back(M);
        sort(dd.begin(), dd.end());
        return dd;
    }
};
struct Combination{
private:
    ll N;
    vector<ll> fac, facinv;

public:
    Combination(ll n){
        N = n;
        fac.push_back(1); fac.push_back(1);
        rep(i,2,N+1) fac.push_back(fac[i-1] * i % MOD);
        rep(i,0,N+1) facinv.push_back(power(fac[i], MOD-2));
    }
    ll power(ll x, ll n){
        if(n == 0) return 1LL;
        ll res = power(x * x % MOD, n/2);
        if(n % 2 == 1) res = res * x % MOD;
        return res;
    }
    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
    }
    ll npk(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[n-k] % MOD;
    }
    ll get(ll x){return fac[x];};
    ll getinv(ll x){return facinv[x];};
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    Integer it;
    Combination cb(100010);
    vector<ll> dd = it.divisor(K);
    vector<ll> fac = it.factor(K);
    ll ans = 0;
    for(auto &e: dd){
        ll val = K;
        val *= cb.power(e, MOD-2);
        val %= MOD;
        vector<ll> v = it.factor(e);
        map<ll,ll> mp;
        rep(i,0,v.size()) mp[v[i]]++;
        vector<ll> alt;
        rep(i,0,fac.size()){
            if(mp[fac[i]] != 0){
                mp[fac[i]]--;
            }else{
                alt.push_back(fac[i]);
            }
        }
        alt.erase(unique(alt.begin(), alt.end()), alt.end());
        ll k = alt.size();
        ll sum = 0;
        rep(bit,0,(1LL<<k)){
            ll cnt = __builtin_popcount(bit);
            ll mul = e;
            rep(i,0,k){
                if((bit>>i) & 1) mul *= alt[i];
            }
            ll n = N / mul;
            ll tt = (2 * mul + (n-1) * mul) % MOD;
            (tt *= n) %= MOD;
            (tt *= cb.power(2,MOD-2)) %= MOD;
            if(cnt % 2 == 0){
                sum += tt;
            }else{
                sum -= tt;
            }
            sum = (sum + MOD) % MOD;
        }
        val *= sum;
        val %= MOD;
        ans += val;
        ans %= MOD;
    }
    print(ans);

    
    
}