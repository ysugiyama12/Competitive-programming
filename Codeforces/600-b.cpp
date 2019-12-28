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
    ll a[100010];
    rep(i,0,N) cin >> a[i];
    map<ll,ll> mp;
    ll cnt = 0;
    bool ok = true;
    vector<ll> pos;
    set<ll> st;
    pos.push_back(0);
    set<ll> used;
    rep(i,0,N){
        // print(st.size());
        if(a[i] > 0){
            if(st.find(a[i]) == st.end()){
                if(used.find(a[i]) != used.end()){
                    ok = false;
                    break;
                }else{
                    st.insert(a[i]);
                }
            }else{
                ok = false;
                break;
            }
        }else{
            if(st.find(-a[i]) == st.end()){
                ok = false;
                break;
            }else{
                st.erase(-a[i]);
                used.insert(-a[i]);
            }
        }
        if(st.size() == 0){
            pos.push_back(i+1);
            used.clear();
        }
    }
    if(not ok){
        print(-1);
        return 0;
    }
    // printa(pos, pos.size());
    ll sz = pos.size();
    if(st.size() != 0){
        print(-1);
        return 0;
    }
    print(sz-1);
    rep(i,0,sz-1) print(pos[i+1] - pos[i]);

    

}