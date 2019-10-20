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
    ll Q;
    cin >> Q;
    while(Q--){
        ll n,r;
        cin >> n >> r;
        vector<ll> x(n);
        rep(i,0,n) cin >> x[i];
        sort(x.begin(), x.end(), greater<ll>());
        x.erase(unique(x.begin(), x.end()), x.end());
        ll m = x.size();
        ll lv = 0, rv = m+1;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            bool ok = true;
            rep(i,0,m){
                if(i >= mid){
                    ll pos = x[i] - r*mid;
                    if(pos > 0){
                        ok = false;
                    }
                }
            }
            if(ok){
                rv = mid;
            }else{
                lv = mid;
            }
        }
        print(rv);



    }
    

}