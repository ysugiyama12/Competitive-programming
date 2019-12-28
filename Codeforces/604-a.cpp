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
        ll N;
        cin >> N;
        vector<ll> p(N+1);
        rep(i,0,N) cin >> p[i];
        vector<ll> v;
        ll tt = 1;
        rep(i,1,N){
            if(p[i-1] != p[i]){
                v.push_back(tt);
                tt = 1;
            }else{
                tt++;
            }
        }
        v.push_back(tt);
        ll sz = v.size();
        ll sum = 0;
        ll idx = 0;
        rep(i,0,sz){
            sum += v[i];
            if(sum > N/2){
                idx = i;
                break;
            }
        }
        if(idx < 3){
            print(0,0,0);
        }else{
            ll g = 0, s = 0, b = 0;
            g = v[0];
            ll pp = 1;
            while(g >= s && pp < idx){
                s += v[pp];
                pp++;
            }
            rep(i,pp,idx) b += v[i];
            if(g < s && g < b){
                print(g,s,b);
            }else{
                print(0,0,0);
            }
        }

    }
    

}