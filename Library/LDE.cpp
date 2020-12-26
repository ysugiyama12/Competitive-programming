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
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
struct LDE{
    // ax + by = c の解を求める
    ll a,b,c,x0,y0;
    bool is_exist=true;
 
    LDE(ll a_,ll b_,ll c_): a(a_),b(b_),c(c_){
        ll g = gcd(a, b);
        if(c % g != 0){
            is_exist = false;
            return;
        }
        extgcd(a, b, x0, y0);

        x0 *= c / g;
        y0 *= c / g;

        a /= g;
        b /= g;
    }
 
    ll extgcd(ll a,ll b,ll &x,ll &y){
        if(b == 0){
            x = 1; y = 0;
            return a;
        }

        ll d = extgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
};

void solve(){
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}