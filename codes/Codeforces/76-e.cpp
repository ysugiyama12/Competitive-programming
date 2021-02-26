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
    ll k1,k2,k3;
    cin >> k1 >> k2 >> k3;
    ll a1[200010], a2[200010], a3[200010];
    rep(i,0,k1) cin >> a1[i];
    rep(i,0,k2) cin >> a2[i];
    rep(i,0,k3) cin >> a3[i];
    sort(a1, a1+k1);
    sort(a2, a2+k2);
    sort(a3, a3+k3);
    ll N = k1 + k2 + k3;
    vector<ll> v;
    rep(i,0,k1) v.push_back(a1[i]);
    rep(i,0,k2) v.push_back(a2[i]);
    rep(i,0,k3) v.push_back(a3[i]);
    ll dp[200010];
    fill(dp, dp+N, INF);
    rep(i,0,N){
        ll pos = lower_bound(dp, dp+N, v[i]) - dp;
        dp[pos] = v[i];
    }
    rrep(i,N-1,0){
        if(dp[i] != INF){
            print(N - (i+1));
            return 0;
        }
    }


}