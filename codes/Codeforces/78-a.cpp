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
        string p,h;
        cin >> p >> h;
        bool ok = false;
        ll nh = h.size();
        sort(p.begin(), p.end());
        rep(i,0,nh){
            rep(j,i,nh){
                string h2 = h.substr(i, j-i+1);
                sort(h2.begin(), h2.end());
                if(p == h2){
                    ok = true;
                    break;
                }
            }
        }
        if(ok){
            print("YES");
        }else{
            print("NO");
        }
    }
    

}