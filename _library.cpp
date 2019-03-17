#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
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

// Union-Find
struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
    }
    ll root(ll x){
        if(x == parent[x]) return x;
        else return parent[x] = root(parent[x]);
    }
    void unite(ll a, ll b){
        a = root(a); b = root(b);
        if(a == b) return;
        parent[a] = b;
        ll sum = num[a] + num[b];
        num[a] = sum;
        num[b] = sum;
    }
    bool same(ll a, ll b){ return root(a) == root(b);}
    ll sz(ll x){ return num[x];}
};

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

// Segment Tree(min)
struct SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v){
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        rep(i,0,sz) node[i+n-1] = v[i];
        rrep(i,n-2,0) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(ll x, ll val){
        x += (n-1);
        node[x] = val;
        while(x > 0){
            x = (x-1)/2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    ll getMin(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];
        ll vl = getMin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getMin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

//行列累乗
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mult(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size(),0));
    rep(i,0,A.size()){
        rep(k,0,B.size()){
            rep(j,0,B[0].size()){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

mat pow_mat(mat A, ll n){
    if(n == 1) return A;
    if(n % 2 == 0){
        mat B = pow_mat(A, n/2);
        return mult(B,B);
    }else{
        mat B = pow_mat(A, n-1);
        return mult(A,B); 
    }
}

void nibutan(){
    ll v[5] = {1,3,5,7,9};
    ll p = lower_bound(v, v+5, 0) - v; // 0
    p = lower_bound(v, v+5, 2) - v; // 1
    p = lower_bound(v, v+5, 3) - v; // 1
    p = upper_bound(v, v+5, 2) - v; // 1
    p = upper_bound(v, v+5, 3) - v; // 2
    p = lower_bound(v, v+5, 10) - v; // 5

}
// 最長回文判定
pair<ll, string> longest_palindrome(string text) {
    ll n = text.size();
    ll rad[2*n], i, j, k;
    for (i = 0, j = 0; i < 2*n; i += k, j = max(j-k, 0LL)) {
    while (i-j >= 0 && i+j+1 < 2*n && text[(i-j)/2] == text[(i+j+1)/2]) ++j;
    rad[i] = j;
    for (k = 1; i-k >= 0 && rad[i]-k >= 0 && rad[i-k] != rad[i]-k; ++k)
        rad[i+k] = min(rad[i-k], rad[i]-k);
    }
    ll len = 0, idx = 0;
    rep(i,0,2*n){
        if(len < rad[i]){
            len = rad[i];
            idx = i;
        }
    }
    string ss;
    if(idx % 2 == 0){
        idx /= 2;
        ss = text.substr(idx - len/2, len);
    }else{
        idx /= 2;
        ss = text.substr(idx - len/2+1, len);
    }
    return make_pair(len, ss);
    //   return *max_element(rad, rad+2*n); // ret. centre of the longest palindrome
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
}
