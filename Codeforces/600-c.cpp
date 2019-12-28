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
    ll N,M;
    cin >> N >> M;
    ll a[200010];
    rep(i,0,N) cin >> a[i];
    sort(a, a+N);
    vector<ll> sum[200010];
    rep(i,0,M){
        sum[i].push_back(0);
    }
    rep(i,0,N){
        ll amari = i % M;
        ll sz = sum[amari].size();
        ll v = sum[amari][sz-1];
        sum[amari].push_back(v + a[i]);
    }
    vector<ll> ans;
    ll res = 0;
    rep(i,0,N){
        ll amari = i % M;
        ll tt = i / M;
        res += sum[amari][tt+1];
        ans.push_back(res);
    }
    printa(ans, N);


    

}