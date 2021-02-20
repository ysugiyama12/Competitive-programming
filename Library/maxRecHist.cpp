/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

void solve(){
    ll N;
    cin >> N;
    vll a(N+1,0);
    rep(i,0,N) cin >> a[i];
    typedef struct{ll h, idx;} P;
    stack<P> st;
    ll ans = 0;
    rep(i,0,N+1){
        if(st.empty()){
            st.push({a[i], i});
        }else{
            P v = st.top();
            if(v.h < a[i]){
                st.push({a[i], i});
            }else if(v.h > a[i]){
                ll target = i;
                while(not st.empty()){
                    P l1 = st.top();
                    if(l1.h >= a[i]){
                        st.pop();
                        ans = max(ans, l1.h * (i - l1.idx));
                        target = l1.idx;
                    }else{
                        break;
                    }
                }
                st.push({a[i], target});
            }
        }
    }
    print(ans);
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}