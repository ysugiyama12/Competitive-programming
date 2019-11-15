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
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    if(A[0] != 0){
        print(0);
        return 0;
    }
    if(N == 1){
        print(1);
        return 0;
    }

    sort(A, A+N);
    if(A[1] == 0){
        print(0);
        return 0;
    }
    rep(i,0,N-1){
        if(A[i+1] - A[i] >= 2){
            print(0);
            return 0;
        }
    }
    ll ans = 1;
    map<ll,ll> mp;
    rep(i,0,N) mp[A[i]]++;
    for(auto &e: mp){
        if(e.first == 0) continue;
        ll num = mp[e.first-1];
        ans *= power((power(2, num) - 1 + MOD) % MOD, e.second) % MOD;
        ans %= MOD;
        ans *= power(2, e.second * (e.second - 1) / 2);
        ans %= MOD;
    }
    print(ans);

    // 0 1 1 1 2 2 2 3 4


    

}