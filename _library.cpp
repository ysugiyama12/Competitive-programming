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
typedef pair<ll, ll> lpair;

inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} //最大公約数
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;} //最小公倍数
inline bool isPrime(ll x){ //素数かどうか判定
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(ll i=3;i<=sqrt(x)+1;i+=2) if(x%i==0) return false;
    return true;
}
inline vector<ll> divisor(ll M){ //約数の全列挙
    vector<ll> dd;
    for(ll i = 1; i*i <= M; i++){
        if(M % i == 0){
            dd.push_back(i);
            if(i * i != M){
                dd.push_back(M/i);
            }
        }
    }
    sort(dd.begin(), dd.end());
    return dd;
}
inline vector<ll> factor(ll M){ //素因数分解
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

// nCk % MODのテーブル作成関数
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

ll parent[200010];

ll root(ll x){
    if(x == parent[x]) return x;
    else return parent[x] = root(parent[x]);
}

void unite(ll a, ll b){
    a = root(a); b = root(b);
    if(a == b) return;
    parent[a] = b;
}

bool same(ll a, ll b){
    return root(a) == root(b);
}

vector<string> split(string str, char del) { //文字列分割
    ll first = 0;
    ll last = str.find_first_of(del);
    vector<string> result;
    if(last == string::npos){
        result.push_back(str);
        return result;
    }
    while (first < str.size()) {
        string subStr(str, first, last - first);

        result.push_back(subStr);

        first = last + 1;
        last = str.find_first_of(del, first);

        if (last == string::npos) {
            last = str.size();
        }
    }
    return result;
}
ll next_combination(ll sub) { //nCkの全列挙(bit)
    ll x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1LL) | y;
}

ll extGcd(ll a, ll b,ll &p, ll &q){
    if(b == 0){
        p = 1; q = 0; return a;
    }
    ll d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

lpair ChineseRem(vector<ll> &b, vector<ll> &m){
    ll r = 0, M = 1;
    ll N = b.size();
    rep(i,0,N){
        ll p,q;
        ll d = extGcd(M, m[i], p, q);
        if((b[i] - r) % d != 0) return make_pair(0,-1);
        ll tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M*tmp;
        M *= m[i]/d;
    }
    return make_pair((r+M) % M, M);
}

vector<ll> decimal(ll x, ll n, ll sz){
    // 数xをn進数でsz桁
    vector<ll> v(sz); ll idx = 0;
    while(x > 0){
        v[idx] = x % n;
        x /= n;
        idx++;
    }
    return v;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
}
