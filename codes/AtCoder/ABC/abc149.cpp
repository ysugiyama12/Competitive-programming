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
ll power(ll x, ll n){
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1) res = res * x % MOD;
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> tree[200010];
    ll N;
    cin >> N;
    ll A[200010], B[200010];
    rep(i,0,N-1){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        tree[B[i]].push_back(A[i]);
    }
    ll ans = 1;
    rep(k,0,N-1){
        
    }

    

}