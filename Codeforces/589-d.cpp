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
    ll N,M;
    cin >> N >> M;
    ll a[300010], b[300010];
    vector<ll> tree[100010];
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    if(M < N-1){
        print(-1);
        return 0;
    }
    ll amari = N * (N-1) / 2 - M;
    ll check[100010] = {};
    ll idx = 1;
    rep(i,0,N) check[i] = 1;
    ll p = -1;
    for(auto &e: tree[0]){
        check[e] = 0;
        p = e;
    }
    if(p == -1){
        print(-1);
        return 0;
    }
    check[p] = 0;
    for(auto &e: tree[p]){
        if(check[e] == 0) check[e] = 2;
    }
    ll c0 = 0, c1 = 0, c2 = 0;
    rep(i,0,N){
        if(check[i] == 0) c0++;
        if(check[i] == 1) c1++;
        if(check[i] == 2) c2++;
    }
    if(c0 == 0 || c1 == 0 || c2 == 0){
        print(-1);
        return 0;
    }
    bool ok = true;
    rep(i,0,M){
        if(check[a[i]] == check[b[i]]) ok = false;
    }
    if(ok && M == c0*c1 + c1*c2 + c2 * c0){
        rep(i,0,N) cout << check[i]+1 << " \n"[i==N-1];
    }else{
        print(-1);
    }
    





    
}