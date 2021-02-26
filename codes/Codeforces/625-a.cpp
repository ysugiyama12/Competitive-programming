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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll b[200010];
    rep(i,0,N) cin >> b[i];
    rep(i,0,N) b[i] -= i+1;
    map<ll,ll> mp;
    rep(i,0,N) mp[b[i]] += b[i] + i+1;
    ll ans = 0;
    for(auto &e: mp){
        ans = max(ans, e.second);
    }
    print(ans);

    

}