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
    ll L[100010], R[100010];
    rep(i,0,N) cin >> L[i] >> R[i];
    vector<ll> lv, rv;
    rep(i,0,N) lv.push_back(L[i]);
    rep(i,0,N) rv.push_back(-R[i]);
    sort(lv.begin(), lv.end(), greater<ll>());
    sort(rv.begin(), rv.end(), greater<ll>());
    ll sum_l[100010] = {}, sum_r[100010] = {};
    rep(i,0,N) sum_l[i+1] += sum_l[i] + lv[i];
    rep(i,0,N) sum_r[i+1] += sum_r[i] + rv[i];
    ll ans = 0;
    rep(i,0,N+1){
        ll res = sum_l[i];
        ll val = -INF;
        if(i > 0){
            val = max(val, sum_r[i-1]);
        }
        val = max(val, sum_r[i]);
        if(i < N){
            val = max(val, sum_r[i+1]);
        }
        res += val;
        ans = max(ans, res);
    }
    print(2 * ans);
    

}