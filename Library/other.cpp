/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

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


vector<ll> compress(vector<ll> x){
	vector<ll> v = x;
    v.push_back(-INF);
    v.push_back(INF);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<ll> res;
    for(auto &e: x){
        res.push_back(lower_bound(v.begin(), v.end(), e) - v.begin());
    }
    return res;
}

void vis_2d(vector< vector<ll> > v, ll h, ll w, ll pad=4){
    cout <<  "ij "; rep(i,0,w) cout << left << setw(pad) << i; cout << endl;
    rep(i,0,h){
        cout << i << ": ";
        rep(j,0,w){ if(v[i][j] == INF) cout << "x" << string(pad-1, ' '); else cout << left << setw(pad) << v[i][j]; }
        cout << endl;
    }
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
}
