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
    while(T--){
        ll x;
        cin >> x;
        string S;
        cin >> S;
        ll sz = S.size();
        bool flg = false;
        rep(i,0,x){
            // print(i,sz);
            if(flg){
                ll add = (sz - (i+1) + MOD) % MOD;
                ll times = S[i] - '0';
                sz += add * (times-1 + MOD) % MOD;
                sz %= MOD;
            }else{
                string sr = S.substr(i+1, sz - (i+1));
                ll times = S[i] - '0';
                rep(j,0,times-1) S += sr;
                sz += sr.size() * (times-1);
                if(sz >= x) flg = true;
            }
        }
        print(sz);

    }
    

}