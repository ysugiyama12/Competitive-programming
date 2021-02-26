/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
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
    ll a[200010], b[200010];
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];
    ll ans = 0;
    map<ll,ll> p1,p2;
    rep(i,0,N){
        p1[a[i]] = i;
        p2[b[i]] = i;
    }
    ll max_pos = -1;
    rep(i,0,N-1){
        ll cur = a[i];
        max_pos = max(max_pos, p2[cur]);
        if(max_pos > p2[a[i+1]]){
            ans++;
        }
    }
    print(ans);
    

}