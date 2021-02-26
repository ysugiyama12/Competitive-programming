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
        vector<ll> a(N+1), b(N+1);
        rep(i,0,N) cin >> a[i];
        rep(i,0,N) cin >> b[i];
        vector<ll> diff;
        rep(i,0,N){
            if(a[i] != b[i]) diff.push_back(i);
        }
        ll sz = diff.size();
        if(sz == 0){
            print("YES");
            continue;
        }
        ll v = diff[sz-1] - diff[0];
        if(v + 1 != sz){
            print("NO");
            continue;
        }
        bool ok = true;
        ll sa = b[diff[0]] - a[diff[0]];
        for(auto &e: diff){
            if(sa != b[e] - a[e]) ok = false;
        }
        if(ok && sa > 0){
            print("YES");
        }else{
            print("NO");
        }

    }
    

}