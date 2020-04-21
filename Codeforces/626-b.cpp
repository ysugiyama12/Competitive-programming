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
    ll a[400010];
    rep(i,0,N) cin >> a[i];
    sort(a, a+N);
    ll ans = 0;
    rrep(bit,27,0){
        print(bit, (1LL<<bit));
        ll n = (1LL<<bit);
        ll n2 = n * 2;
        rep(i,0,N){
            a[i] %= n2;
        }
        sort(a, a+N);
        // print("=--");
        // printa(a, N);
        ll res = 0;
        // print(n);
        rep(i,0,N){
            ll l1 = n - a[i], r1 = n2 - a[i]-1;
            // print(l1,r1);

            ll l2 = l1 + n2, r2 = r1 + n2-1;
            // print(l2,r2);

            ll p1 = upper_bound(a, a+N, r1) - a;
            ll p2 = lower_bound(a, a+N, l1) - a;
            // print(p1,p2);
            p2 = max(p2, i+1);
            ll diff = p1 - p2;
            if(diff > 0) res += diff;
            // print(diff);
            p1 = upper_bound(a, a+N, r2) - a;
            p2 = lower_bound(a, a+N, l2) - a;
            p2 = max(p2, i+1);
            diff = p1 - p2;
            if(diff > 0) res += diff;
        }
        // print(res);
        if(res % 2 == 1){
            ans += (1LL<<bit);
        }

    }
    print(ans);
    

}