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

void solve(){
    ll N,Q,K;
    cin >> N >> Q >> K;
    vll a(N);
    rep(i,0,N) cin >> a[i];
    vll l(Q), r(Q);
    rep(i,0,Q){
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    vll sum(N+1, 0);
    rep(i,0,N){
        if(i == 0 || i == N-1){
            sum[i+1] += sum[i];
        }else{
            ll v = a[i+1] - a[i-1] - 2;
            sum[i+1] = sum[i] + v;          
        }
    }

    rep(i,0,Q){
        ll ans = 0;
        if(l[i] == r[i]){
            ans = K-1;
        }else{
            ans += sum[r[i]] - sum[l[i]+1];
            ans += (K+1) - a[r[i]-1] - 2;
            ans += a[l[i]+1] - 2;
        }
        print(ans);
    }

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}