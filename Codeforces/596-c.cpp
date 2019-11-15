/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,P;
    cin >> N >> P;
    ll ans = 1;
    if(P == 0){
        ll cnt = 0;
        rep(i,0,61){
            if((N>>i) & 1) cnt++;
        }
        print(cnt);
        return 0;
    }
    while(1){
        ll v = N - ans * P;
        if(v <= 0) break;
        ll cnt = 0;
        rep(i,0,61){
            if((v>>i) & 1) cnt++;
        }
        if(ans >= cnt && ans <= v){
            print(ans);
            return 0;
        }
        ans++;
    }
    print(-1);

    

}