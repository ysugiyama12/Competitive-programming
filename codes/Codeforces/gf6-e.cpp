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
    ll a[200010];
    rep(i,0,N) cin >> a[i];
    ll Q;
    cin >> Q;
    ll s[100010], t[100010], u[100010];
    rep(i,0,Q){
        cin >> s[i] >> t[i] >> u[i];
        s[i]--;
    }
    ll free_cnt[200010] = {};
    map<lpair,ll> mp;
    ll cost = 0;
    rep(i,0,N) cost += a[i];
    rep(i,0,Q){
        if(mp[{s[i], t[i]}] == 0){
            // print(i);
            mp[{s[i], t[i]}] = u[i];
            if(u[i] == 0){
                print(cost);
                continue;
            }
            free_cnt[u[i]-1]++;
            // print(i, free_cnt[u[i]-1]);
            if(free_cnt[u[i]-1] <= a[u[i]-1]) cost--;
            print(cost);
        }else{
            // print(i, free_cnt[mp[{s[i],t[i]}]-1]);
            if(free_cnt[mp[{s[i],t[i]}]-1] <= a[mp[{s[i],t[i]}]-1]) cost++;
            free_cnt[mp[{s[i],t[i]}]-1]--;
            mp[{s[i],t[i]}] = u[i];
            if(u[i] == 0){
                print(cost);
                continue;
            }
            free_cnt[u[i]-1]++;
            if(free_cnt[u[i]-1] <= a[u[i]-1]) cost--;
            print(cost);
            
        }

    }

    

}