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
    string S;
    cin >> S;
    ll N = S.size();
    vector<ll> v1,v2;
    rep(i,0,N){
        if(S[i] == '('){
            v1.push_back(i);
        }else{
            v2.push_back(i);
        }
    }
    sort(v2.begin(), v2.end(), greater<ll>());
    ll ans = 0;
    ll sz = min(v1.size(), v2.size());
    vector<ll> res;
    rep(i,0,sz){
        if(v1[i] < v2[i]){
            res.push_back(v1[i]+1);
            res.push_back(v2[i]+1);
        }
    }
    if(res.size() == 0){
        print(0);
    }else{
        print(1);
        sort(res.begin(), res.end());
        print(res.size());
        printa(res, res.size());
    }


    

}