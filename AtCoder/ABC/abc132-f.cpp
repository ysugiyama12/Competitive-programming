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
ll dp[110][200010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    vector<ll> v;
    vector<ll> max_val;
    vector<ll> cnt;
    ll num = 0;
    for(ll i = 1; i * i <= N; i++){
        dp[1][i] = 1;
        v.push_back(i);
        num = i;
        max_val.push_back(N/i);
        cnt.push_back(1);
    }
    ll cur = num+1;
    ll idx = num+1;
    rrep(i,num,1){
        ll tt = N / i;
        if(i == num && tt == i) continue;
        ll diff = tt - cur + 1;
        // print(cur, i, diff);
        v.push_back(cur);
        dp[1][idx] = diff;
        idx++;
        cur = tt+1;
        max_val.push_back(i);
        cnt.push_back(diff);
    }
    // printa(v, v.size());
    // printa(max_val, max_val.size());
    // printa(cnt, cnt.size());
    ll sz = max_val.size();
    // print(sz);
    // rep(i,0,sz){
    //     cout << v[i] << "-" << v[i] + cnt[i]-1 << " \n"[i==sz-1];
    // }
    rep(i,1,K){
        rep(n,0,sz){
            ll val = max_val[n];
            ll pos = upper_bound(v.begin(), v.end(), val) - v.begin();
            // print(pos);
            dp[i+1][1] += dp[i][n+1];
            dp[i+1][pos+1] = (dp[i+1][pos+1] - dp[i][n+1] + MOD) % MOD;
            dp[i+1][1] %= MOD;
        }
        rep(n,1,sz) (dp[i+1][n+1] += dp[i+1][n] + MOD) %= MOD;
        rep(n,1,sz+1) (dp[i+1][n] *= cnt[n-1]) %= MOD;
    }
    ll ans = 0;
    rep(n,1,sz+1) (ans += dp[K][n]) %= MOD;
    print(ans);
}