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
    ll p[300010], q[300010];
    rep(i,0,N) cin >> p[i];
    rep(i,0,N) cin >> q[i];
    ll ans[300010] = {};
    map<ll,bool> mp;
    rep(i,0,N){
        set<ll> st;
        rep(j,0,N){
            st.insert(p[j]);
            if(mp[j+1] == true){
                auto itr = st.end();
                itr--;
                st.erase(itr);
            }
        }

        auto itr2 = st.end();
        itr2--;
        ans[i] = *itr2;
        mp[q[i]] = true;
    }
    printa(ans, N);
    

}