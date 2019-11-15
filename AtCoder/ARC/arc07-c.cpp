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
    string S;
    cin >> S;
    ll N = S.size();
    ll num = N - 1;
    ll ans = INF;
    rep(bit,0,(1LL<<num)){
        ll cnt = __builtin_popcount(bit);
        ll check[11] = {};
        rep(i,0,N){
            if(S[i] == 'o') check[i]++;
        }
        rep(i,0,num){
            if((bit>>i) & 1){
                ll start = i+1;
                rep(j,0,N){
                    if(start + j <= N-1){
                        if(S[j] == 'o') check[start+j]++;
                    }
                }
                rep(j,0,N){
                    if(start - j-1 >= 0){
                        if(S[N-1-j] == 'o') check[start-j-1]++;
                    }
                }

            }
        }
        bool ok = true;
        rep(j,0,N){
            if(check[j] == 0) ok = false;
        }
        if(ok) ans = min(ans, cnt);
    }
    print(ans+1);
}