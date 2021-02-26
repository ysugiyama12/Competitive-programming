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
vector<ll> tree[5010];
struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;
    vector<ll> diff_weight;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
        rep(i,0,N) diff_weight.push_back(0);
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
    ll h[5010] = {};
    ll u[5010], v[5010];
    rep(i,0,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        h[v[i]]++;
        tree[u[i]].push_back(v[i]);
    }
    stack<ll> st;
    rep(i,0,N){
        if(h[i] == 0) st.push(i);
    }
    vector<ll> ans;
    while(not st.empty()){
        ll p = st.top();
        st.pop();
        ans.push_back(p);
        for(auto &e: tree[p]){
            h[e]--;
            if(h[e] == 0) st.push(e);
        }
    }
    if(ans.size() == N){
        print(1);
        rep(i,0,M) cout << "1" << " \n"[i==M-1];
    }else{
        UnionFind uf(5010);
        ll h2[5010] = {};
        rep(i,0,N){
            for(auto &e: tree[i]){
                if(h[i] != 0 && h[e] != 0){
                    uf.unite(i, e);
                    h2[i]++;
                }
            }
        }
        ll is_check[5010] = {};
        map<lpair,ll> mp;
        rep(i,0,N){
            if(is_check[i]) continue;

            ll max_val = 0;
            rep(j,0,N){
                if(uf.same(i, j)){
                    is_check[j] = 1;
                    max_val = max(max_val, h2[j]);
                }
            }
            if(max_val == 1){
                

            }

        }


        
    }

}