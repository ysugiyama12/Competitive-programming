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
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> mp(26, 0);
    map< vector<ll>, vector<ll> > hash_val;
    rep(i,0,26){
        mp[i] = 0;
    }
    rep(i,0,K){
        mp[S[i] - 'a']++;
    }
    hash_val[mp].push_back(0);
    rep(i,K,N){
        mp[S[i-K] - 'a']--;
        mp[S[i] - 'a']++;
        hash_val[mp].push_back(i-K+1);
    }
    bool ok = false;
    for(auto &e: hash_val){
        ll sz = e.second.size();
        if(sz <= 1) continue;
        ll v1 = e.second[0], v2 = e.second[sz-1];
        if(v1 + K <= v2) ok = true;
    }
    if(ok){
        print("YES");
    }else{
        print("NO");
    }

    

}