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
    string S;
    cin >> S;
    ll c1 = 0, c2 = 0;
    rep(i,0,N){
        if(S[i] == '(') c1++;
        else c2++;
    }
    if(c1 != c2){
        print(-1);
        return 0;
    }
    ll start = 0;
    ll cnt = 0;
    ll ans = 0;
    bool ok = true;
    rep(i,0,N){
        if(S[i] == '('){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt < 0) ok = false;
        if(cnt == 0){
            if(not ok){
                ans += i - start + 1;
            }
            start = i+1;
            ok = true;
        }
    }
    print(ans);
    

}