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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
class xor_set{
private:
    vll w;
public:
    xor_set () {}
    void insert(ll x){
        for(ll v : w) if(v & -v & x) x ^= v;
        if(x == 0) return;
        for(ll& v : w) if(x & -x & v) v ^= x;
        w.push_back(x);
    }
 
    bool contain(ll x){
        for(ll v : w) if(v & -v & x) x ^= v;
        if(x == 0) return true;
        return false;
    }
};

void solve(){
    ll N;
    cin >> N;
    vll a(N);
    rep(i,0,N) cin >> a[i];
    string S;
    cin >> S;
    vector<map<ll,bool> > dp(N+1);
    xor_set xs;

    rrep(i,N-1,0){
        if(S[i] == '0'){
            xs.insert(a[i]);
        }else{
            if(not xs.contain(a[i])){
                print(1);
                return;
            }
        }
    }
    print(0);
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) solve();
}