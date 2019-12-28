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
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll red = 0, blue = 0, green = 0;
    ll ans = 1;
    rep(i,0,N){
        if(red == blue && blue == green){
            if(red != A[i]){
                return 0;
            }
            ans *= 3;
            ans %= MOD;
            red++;
        }else if(red == blue){
            if(A[i] == red){
                ans *= 2;
                ans %= MOD;
                red++;
            }else if(A[i] == green){
                green++;
            }else{
                return 0;
            }
        }else if(blue == green){
            if(A[i] == blue){
                ans *= 2;
                ans %= MOD;
                blue++;
            }else if(A[i] == red){
                red++;
            }else{
                return 0;
            }
        }else if(red == green){
            if(A[i] == red){
                ans *= 2;
                ans %= MOD;
                red++;
            }else if(A[i] == blue){
                blue++;
            }else{
                return 0;
            }
        }else{
            if(A[i] == red){
                red++;
            }else if(A[i] == blue){
                blue++;
            }else if(A[i] == green){
                green++;
            }else{
                return 0;
            }
        }
    }
    print(ans);

}
