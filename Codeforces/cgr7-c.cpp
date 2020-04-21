/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 998244353;
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
    ll N,K;
    cin >> N >> K;
    ll p[200010];
    rep(i,0,N) cin >> p[i];
    ll max_val = 0;
    rep(i,0,K) max_val += N-i;
    ll res = 1;
    vector<ll> pos;
    rep(i,0,N){
        if(p[i] >= N-K+1){
            pos.push_back(i);
        }
    }
    ll sz = pos.size();
    rep(i,0,sz-1){
        res *= pos[i+1] - pos[i];
        res %= MOD;
    }
    print(max_val, res);
    

    

}