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

inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll b[200010];
    rep(i,0,N) cin >> b[i];
    vector<ll> v[62];
    rep(i,0,N){
        ll cnt = 0;
        ll tt = b[i];
        while(tt % 2 == 0){
            tt /= 2;
            cnt++;
        }
        v[cnt].push_back(b[i]);
    }
    ll max_val = 0, idx = 0;
    rep(i,0,61){
        if(max_val < v[i].size()){
            max_val = v[i].size();
            idx = i;
        }
    }
    ll m = N - max_val;
    map<ll,ll> mp;
    for(auto &e: v[idx]) mp[e]++;
    vector<ll> ans;
    rep(i,0,N){
        if(mp[b[i]] == 0) ans.push_back(b[i]);
    }
    print(m);
    printa(ans, ans.size());



    

    
}