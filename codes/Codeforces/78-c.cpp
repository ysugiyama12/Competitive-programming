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
        vector<ll> a(2*N+1);
        rep(i,0,2*N) cin >> a[i];
        vector<ll> v(2*N+1, 0);
        ll cnt1 = 0, cnt2 = 0;
        rep(i,0,2*N){
            if(a[i] == 1) cnt1++;
            else cnt2++;
        }
        ll diff = cnt1 - cnt2;
        if(diff == 0){
            print(0);
            continue;
        }
        ll val = 0;
        rrep(i,N-1,0){
            if(a[i] == 1){
                val++;
            }else{
                val--;
            }
            v[i] = val;
        }
        val = 0;
        rep(i,N,2*N){
            if(a[i] == 1){
                val++;
            }else{
                val--;
            }
            v[i] = val;  
        }
        map<ll,ll> most_left;
        rrep(i,2*N-1, N){
            most_left[v[i]] = i;
        }
        ll ans = INF;
        rep(i,0,N){
            if(v[i] == diff){
                ans = min(ans, N-i);
            }else{
                ll p1 = most_left[diff - v[i]];
                if(p1 == 0) continue;
                ans = min(ans, N-i + p1 - N + 1);
            }
        }
        if(most_left[diff] != 0){
            ans = min(ans, most_left[diff] - N + 1);
        }
        print(ans);
        



    }
    

}