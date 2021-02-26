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
    ll N,X;
    cin >> N >> X;
    ll w[35];
    rep(i,0,N) cin >> w[i];
    ll n = N/2;
    map<ll,ll> mp1, mp2;
    rep(bit,0,(1LL<<n)){
        ll v = 0;
        rep(i,0,n){
            if((bit>>i) & 1) v += w[i];
        }
        mp1[v]++;
    }
    rep(bit,0,(1LL<<(N-n))){
        ll v = 0;
        rep(i,0,N-n){
            if((bit>>i) & 1) v += w[n + i];
        }
        mp2[v]++;
    }
    ll ans = 0;
    for(auto &e: mp1){
        if(e.first > X) continue;
        ans += e.second * mp2[X - e.first];
    }
    print(ans);

}