#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
ll N,M;
ll A[400010], B[400010], C[400010];
vector<lpair> tree[400010];
typedef struct{
    ll from;
    ll to;
    ll cost;
    ll idx;
} ee;
vector<ee> vv;
// Union-Find
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
bool comp(ee e1, ee e2){
    return e1.cost < e2.cost;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(make_pair(B[i], C[i]));
        tree[B[i]].push_back(make_pair(A[i], C[i]));
        ee tmp = {A[i], B[i], C[i], i};
        vv.push_back(tmp);
    }
    sort(vv.begin(), vv.end(), comp);
    ll Q;
    cin >> Q;
    ll S[100010], T[100010];
    rep(i,0,Q){
        cin >> S[i] >> T[i];
        S[i]--; T[i]--;
    }
    // if(Q != 1) return 0;
    ll ans = 0;
    UnionFind uf(4010);
    ll use[400010] = {};
    rep(i,0,M){
        ee e1 = vv[i];
        if(!uf.same(e1.from, e1.to)){
            uf.unite(e1.from, e1.to);
            ans += e1.cost;
            use[e1.idx] = 1;
        }
    }
    map<lpair, ll> mp;
    print(use)
    rep(i,0,M){
        if(use[i] == 0) continue;
        if(A[i] > B[i]) swap(A[i], B[i]);
        lpair l1 = make_pair(A[i], B[i]);
        mp[l1] = C[i];
    }
    rep(i,0,Q){
        if(S[i] > T[i]) swap(S[i], T[i]);
        if(mp[make_pair(S[i], T[i])] != 0){
            ll v = ans - mp[make_pair(S[i], T[i])];
        }else{
            ll v = ans;
        }
        print(ans);
    }

    
    
}