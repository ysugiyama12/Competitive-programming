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
    ll M = (1LL<<N);
    vector<ll> s(M+1);
    rep(i,0,M) cin >> s[i];
    sort(s.rbegin(), s.rend());
    multiset<ll> mt;
    rep(i,1,M) mt.insert(s[i]);
    vector<ll> v;
    v.push_back(s[0]);
    rep(i,0,N){
        ll sz = v.size();
        rep(j,0,sz){
            ll e = v[j];
            auto itr = mt.lower_bound(e);
            if(itr == mt.begin()){
                print("No");
                return 0;
            }
            itr--;
            ll val = *itr;
            v.push_back(val);
            mt.erase(itr);
        }
        sort(v.rbegin(), v.rend());
    }
    print("Yes");

    

}