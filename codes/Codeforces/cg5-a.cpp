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
    ll a[15000];
    rep(i,0,N) cin >> a[i];
    ll cnt = 0;
    rep(i,0,N){
        if(abs(a[i]) % 2 == 1) cnt++;
    }
    ll tt = 0;
    rep(i,0,N){
        if(abs(a[i]) % 2 == 0){
            print(a[i]/2);
        }else{
            if(tt < cnt/2){
                print((a[i]+1)/2);
            }else{
                print((a[i]-1)/2);
            }
            tt++;
        }
    }
    

}