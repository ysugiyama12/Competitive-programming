#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;
    vector<ll> diff_weight;
    vector<ll> rank;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
        rep(i,0,N) diff_weight.push_back(0);
        rep(i,0,N) rank.push_back(0);
    }
    ll root(ll x){
        if(x == parent[x]){
            return x;
        }else{
            ll r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }
    void unite(ll a, ll b, ll w = 0){
        w += weight(a); w -= weight(b);
        a = root(a); b = root(b);
        if(a == b) return;
        parent[b] = a;
        ll sum = num[a] + num[b];
        num[a] = sum;
        num[b] = sum;
        diff_weight[b] = w;
    }

    bool same(ll a, ll b){ return root(a) == root(b);}
    ll sz(ll x){ return num[x];}

    ll weight(ll x){
        root(x);
        return diff_weight[x];
    }

    ll diff(ll a, ll b){
        return weight(b) - weight(a);
    }
};
int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[100010], B[100010];
    rep(i,0,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    UnionFind uf(100010);
    ll v = N*(N-1)/2;
    vector<ll> ans;
    ans.push_back(v);
    rrep(i,M-1,0){
        if(uf.same(A[i], B[i])){
            ans.push_back(v);
        }else{
            v -= uf.sz(uf.root(A[i])) * uf.sz(uf.root(B[i]));
            uf.unite(A[i], B[i]);
            ans.push_back(v);
        }
    }
    rrep(i,M-1,0){
        print(ans[i]);
    }
}
