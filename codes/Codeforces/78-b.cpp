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
    ll T;
    cin >> T;
    vector<ll> odd, even;
    map<ll,ll> cnt;
    rep(i,1,100001){
        if((i-1) % 4 <= 1){
            odd.push_back(i*(i+1)/2);
        }else{
            even.push_back(i*(i+1)/2);
        }
        cnt[i*(i+1)/2] = i;
    }
    while(T--){
        ll a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        if(a == b){
            print(0);
            continue;
        }
        ll diff = b - a;
        // print(diff);
        if(diff % 2 == 0){
            ll pos = lower_bound(even.begin(), even.end(), diff) - even.begin();
            print(cnt[even[pos]]);

        }else{
            ll pos = lower_bound(odd.begin(), odd.end(), diff) - odd.begin();
            print(cnt[odd[pos]]);

        }
    }

}