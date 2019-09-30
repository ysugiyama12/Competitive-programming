/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
void print() {}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail){ cout << head << " \n"[sizeof...(tail) == 0]; print(forward<Tail>(tail)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll L,R;
    cin >> L >> R;
    rep(i,L,R+1){
        string n = to_string(i);
        map<ll,ll> mp;
        rep(j,0,n.size()){
            mp[n[j] - '0']++;
        }
        bool ok = true;
        for(auto &e: mp){
            if(e.second != 1) ok = false;
        }
        if(ok){
            print(i);
            return 0;
        }
    }
    print(-1);


    
}