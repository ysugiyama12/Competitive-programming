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
ll a[1000010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    stack<lpair> st;
    st.push({a[0], 1});
    rep(i,1,N){
        lpair now = {a[i], 1};
        while(not st.empty()){
            lpair l1 = st.top();
            if(l1.first * now.second > l1.second * now.first){
                st.pop();
                now = {l1.first+now.first, l1.second + now.second};
            }else{
                break;
            }
        }
        st.push(now);
    }
    vector<double> ans;
    while(not st.empty()){
        lpair l1 = st.top();
        st.pop();
        rep(i,0,l1.second) ans.push_back((double) l1.first / (double) l1.second);
    }
    reverse(ans.begin(), ans.end());
    for(auto &e: ans){
        printf("%.10f\n", e);
    }
    

}