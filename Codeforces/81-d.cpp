/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    Integer it;
    while(T--){
        ll A,M;
        cin >> A >> M;
        ll v = it.gcd(A,M);
        // A /= v; M /= v;
        ll aa = A/v, mm = M/v;
        vector<ll> dd = it.factor(mm);
        dd.erase(unique(dd.begin(), dd.end()), dd.end());
        ll sz = dd.size();
        ll ans = 0;
        rep(bit,1,(1LL<<sz)){
            ll cnt = __builtin_popcount(bit);
            ll res = 0;
            ll mul = 1;
            rep(i,0,sz){
                if((bit>>i) & 1){
                    mul *= dd[i];
                }
            }
            ll amari = mul - aa % mul;
            ll start = 0;
            ll tt = M - amari;
            ll end = (M-1) / mul;
            res = end - start+1;
            
            if(cnt % 2 == 1){
                ans += res;
            }else{
                ans -= res;
            }
        }
        ans = M - ans;
        print(ans / v);



    }
    

}