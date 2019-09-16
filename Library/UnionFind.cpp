/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
    }
    ll root(ll x){
        if(x == parent[x]) return x;
        else return parent[x] = root(parent[x]);
    }
    void unite(ll a, ll b){
        a = root(a); b = root(b);
        if(a == b) return;
        parent[a] = b;
        ll sum = num[a] + num[b];
        num[a] = sum;
        num[b] = sum;
    }
    bool same(ll a, ll b){ return root(a) == root(b);}
    ll sz(ll x){ return num[x];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    UnionFind uf(100010);
    
}