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
    ll A[110];
    rep(i,0,N) cin >> A[i];
    sort(A, A+N);
    ll max_val = A[N-1];
    ll min_val = A[0];
    if(min_val != (max_val + 1) / 2){
        print("Impossible");
        return 0;
    }
    map<ll,ll> mp;
    rep(i,0,N) mp[A[i]]++;
    if(max_val % 2 == 0){
        bool ok = true;
        if(mp[min_val] != 1) ok = false;
        rep(i,min_val+1, max_val+1){
            if(mp[i] < 2) ok = false;
        }
        if(ok){
            print("Possible");
        }else{
            print("Impossible");
        }
    }else{
        bool ok = true;
        if(mp[min_val] != 2) ok = false;
        rep(i,min_val+1, max_val+1){
            if(mp[i] < 2) ok = false;
        }
        if(ok){
            print("Possible");
        }else{
            print("Impossible");
        }
    }

    

}