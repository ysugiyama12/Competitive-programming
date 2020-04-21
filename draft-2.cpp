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
    ll A[2010];
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    rep(i,0,N+1){
        vector<lpair> lv, rv;
        rep(j,0,N){
            if(j < i){
                lv.push_back({A[j], j});
            }else{
                rv.push_back({A[j], j});
            }
        }
        sort(lv.begin(), lv.end());
        sort(rv.begin(), rv.end(), greater<lpair>());
        ll res = 0;
        ll idx = 0;
        for(auto &e: rv){
            res += e.first * abs(e.second - idx);
            idx++; 
        }
        for(auto &e: lv){
            res += e.first * abs(e.second - idx);
            idx++;
        }
        ans = max(ans,res);
    }
    print(ans);

    

}
