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

ll power(ll x, ll n){
    if(n == 0) return 1LL;
    ll res = power(x * x, n/2);
    if(n % 2 == 1) res = res * x;
    return res;
}

void solve(){
    ll N;
    cin >> N;
    ll a[100010];
    rep(i,0,N) cin >> a[i];
    Integer it;
    vector<int> num[200010];

    rep(i,0,N){
        vector<ll> dd = it.factor(a[i]);
        map<int,int> cnt;
        for(auto &e: dd){
            cnt[e]++;
        }
        for(auto &e: cnt){
             num[e.first].push_back(e.second);
        }
    }
    rep(i,1,200001){
        sort(num[i].begin(), num[i].end());
    }
    ll ans = 1;
    rep(i,1,200001){
        ll sz = num[i].size();
        if(sz <= N-2) continue;
        if(sz == N - 1){
            ans *= power(i, num[i][0]);
        }else{
            ans *= power(i, num[i][1]);
        }
    }
    print(ans);



}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}