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

ll gcd(ll a,ll b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a,ll b){return a / gcd(a, b) * b;}

bool isPrime(ll x){
    if(x < 2) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(ll i = 3;i <= sqrt(x) + 1;i += 2) if(x % i == 0) return false;
    return true;
}

vector<ll> divisor(ll M){
    vector<ll> div;
    for(ll i = 1; i * i <= M; i++){
        if(M % i == 0){
            div.push_back(i); if(i * i != M) div.push_back(M / i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}

vector<ll> factor(ll M){
    vector<ll> fac;
    if(M == 1){
        fac.push_back(1); return fac;
    }
    for(ll i = 2; i*i <= M; i++){
        while(M % i == 0){
            fac.push_back(i); M /= i;
        }
    }
    if(M != 1) fac.push_back(M);
    sort(fac.begin(), fac.end());
    return fac;
}

bool isSquare(ll x){
    ll lv = 0, rv = sqrt(x)+100;
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

vector<ll> sieve(ll n){ //エラトステネス
    vector<bool> is_prime(n+1);
    vector<ll> prime;
    rep(i,0,n+1) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    rep(i,2,n+1){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return prime;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
}