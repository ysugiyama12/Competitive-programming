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

vector<ll> compress(vector<ll> v){
    ll n = v.size();
    vector<ll> v2;
    rep(i,0,n) v2.push_back(v[i]);
    sort(v2.begin(), v2.end());
    vector<ll> res;
    rep(i,0,n){
        ll pos = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
        res.push_back(pos + 1); 
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
}
