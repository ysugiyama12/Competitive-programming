/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 998244353;
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

    bool isSquare(ll x){
        ll lv = 0, rv = x+1;
        while(rv - lv > 1){
            ll mid = (lv + rv) / 2;
            if(mid * mid >= x){
                rv = mid;
            }else{
                lv = mid;
            }
        }
        if(rv * rv == x){
            return true;
        }else{
            return false;
        }
    }

    vector<ll> divisor(ll M){ //約数の全列挙
        vector<ll> dd;
        for(ll i = 1; i * i <= M; i++){
            if(M % i == 0){
                dd.push_back(i);
                if(i * i != M){
                    dd.push_back(M / i);
                }
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

Combination cb(100010);
vector<ll> divs[200010];
ll A[200010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N) cin >> A[i];
    map<ll,ll> mp;

    sort(A, A+N, greater<ll>());

    Integer it;
    rep(i,0,N) divs[i] = it.divisor(A[i]);
    rep(i,0,N){
        for(auto &e: divs[i]){
            mp[e]++;
        }
    }
    ll ans = 0;
    rep(i,0,N){
        ll num = A[i];
        for(auto &gcd: divs[i]){
            ll res = num;
            ll sum = 0;
            vector<ll> dd = it.divisor(gcd);
            sum += mp[gcd];
            ll v = num / gcd;
            vector<ll> d2 = it.factor(v);
    
            // for(auto &e: dd){
            //     if(dd % e)
            // }
            // rep(j,i+1,N){
            //     if(it.gcd(num, A[j]) == gcd){
            //         sum += A[j];
            //     }
            // }

            res *= sum;
            res %= MOD;
            res *= cb.power(gcd, MOD-2);
            res %= MOD;
            ans += res;
            ans %= MOD;
        }
    }
    print(ans);


    
}