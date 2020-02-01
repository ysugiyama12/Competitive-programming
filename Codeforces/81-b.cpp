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
        string S,T;
        cin >> S >> T;
        ll ns = S.size(), nt = T.size();
        map<char,ll> mp;
        rep(i,0,ns) mp[S[i]]++;
        bool ok = true;
        rep(i,0,nt){
            if(mp[T[i]] == 0) ok = false;
        }
        if(not ok){
            print(-1);
            continue;
        }
        ll ans = 0;
        vector<ll> nxt[27];
        rep(i,0,ns){
            nxt[S[i] - 'a'].push_back(i);
        }
        ll cur = -1;
        rep(i,0,nt){
            ll c = T[i] - 'a';
            ll ps = upper_bound(nxt[c].begin(), nxt[c].end(), cur) - nxt[c].begin();
            if(ps == nxt[c].size()){
                cur = nxt[c][0];
                ans++;
            }else{
                cur = nxt[c][ps];
            }
        }
        print(ans+1);
    }

}