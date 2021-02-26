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
        ll N,A,B;
        cin >> N >> A >> B;
        ll lv = 0, rv = N;
        ll sum = A + B;
        ll ans1 = 0, ans2 = 0;

        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            ll a1 = 0, b1 = 0;
            ll cnt = 0;
            if(A <= mid){
                a1 = mid+1;
                cnt++;
            }else{
                a1 = mid;
            }
            if(B <= mid){
                b1 = mid+1;
                cnt++;
            }else{
                b1 = mid;
            }
            ll val = 0;
            val = max(a1,b1) + 1;
            if(val <= sum){
                lv = mid;
            }else{
                rv = mid;
            }
        }
        ans2 = lv+1;
        lv = 0, rv = N;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            ll a1 = 0, b1 = 0;
            ll cnt = 0;
            if(A >= N - mid + 1){
                a1 = N - mid;
                cnt++;
            }else{
                a1 = N - mid + 1;
            }
            if(B >= N - mid + 1){
                b1 = N - mid;
                cnt++;
            }else{
                b1 = N - mid + 1;
            }
            ll val = 0;
            val = min(a1,b1) + N;
            if(val > sum){
                lv = mid;
            }else{
                rv = mid;
            }
        }   
        ans1 = N - lv;
        print(ans1, ans2);


        
    }
    

}