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
    ll p[200010];
    rep(i,0,N) cin >> p[i];
    ll ans[200010] = {};
    bool use[200010] = {};
    rep(i,0,N/2){
        ll min_val = INF, min_pos = -1;
        ll cnt = 0;
        rep(j,0,N){
            if(not use[j]){
                cnt++;
                if(cnt % 2 == 1){
                    if(min_val > p[j]){
                        min_val = p[j];
                        min_pos = j;
                    }
                }
            }
        }
        ll cnt2 = 0;
        rep(j,min_pos+1,N){
            if(not use[j]){
                cnt2++;
                if()

            }
        }

    }


}