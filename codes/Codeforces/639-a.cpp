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
    ll t;
    cin >> t;
    while(t--){
        ll N;
        cin >> N;
        vector<ll> a(N);
        rep(i,0,N) cin >> a[i];
        vector<ll> b(N,0);
        rep(i,0,N){
            if(a[i] > 0){
                b[i] = (a[i] + i) % N;
            }else{
                b[i] = (a[i] % N + N + i) % N;
            }
        }
        map<ll,ll> mp;
        rep(i,0,N) mp[b[i]]++;
        bool ok = true;
        for(auto &e: mp){
            if(e.second > 1) ok = false;
        }
        if(ok){
            print("YES");
        }else{
            print("NO");
        }
    }
    

}