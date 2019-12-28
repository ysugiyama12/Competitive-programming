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
vector<lpair> tree[100010];
vector<lpair> tree2[100010];
lpair state[100010];
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
    
    ll sz(ll x){ return num[root(x)];}

    ll weight(ll x){
        root(x);
        return diff_weight[x];
    }

    ll diff(ll a, ll b){
        return weight(b) - weight(a);
    }
};
UnionFind uf(100010);

void dfs(ll cur, ll par, ll s, ll n){
    for(auto &e: tree[cur]){
        if(e.first == par) continue;
        if(s == 0){
            state[e.first] = {1, e.second - n};
            dfs(e.first, cur, 1, e.second - n);
        }else{
            state[e.first] = {0, e.second - n};
            dfs(e.first, cur, 0, e.second - n);
        }
    }

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll u[100010], v[100010], s[100010];
    rep(i,0,M){
        cin >> u[i] >> v[i] >> s[i];
        u[i]--; v[i]--;
    }
    if(M == N-1){
        rep(i,0,M){
            tree[u[i]].push_back({v[i], s[i]});
            tree[v[i]].push_back({u[i], s[i]});
        }
        state[0] = {0, 0};
        dfs(0, -1, 0, 0);
        // rep(i,0,N) print(state[i].first, state[i].second);
        ll max_val = INF, min_val = -INF;
        rep(i,0,N){
            if(state[i].first == 0){
                min_val = max(min_val, -state[i].second + 1);
            }else{
                max_val = min(max_val, state[i].second - 1);
            }
        }
        // print(max_val, min_val);
        ll ans = max(0LL, max_val - min_val + 1);
        print(ans);
    }else{
        rep(i,0,M){
            if(not uf.same(u[i], v[i])){
                uf.unite(u[i], v[i]);
                tree[u[i]].push_back({v[i], s[i]});
                tree[v[i]].push_back({u[i], s[i]});            
            }
        }
        state[0] = {0,0};
        dfs(0, -1, 0, 0);
        bool ok = true;
        ll ans = -1;
        rep(i,0,M){
            if(state[u[i]].first != state[v[i]].first){
                if(state[u[i]].second + state[v[i]].second != s[i]) ok = false;
            }else{
                if(state[u[i]].first == 0){
                    ll val = s[i] - state[u[i]].second - state[v[i]].second;
                    if(val % 2 == 1 || val <= 0){
                        ok = false;
                    }else{
                        ll aa = val / 2;
                        if(ans == -1){
                            ans = aa;
                        }else{
                            if(ans != aa) ok = false;
                        }
                    }
                }else{
                    ll val = state[u[i]].second + state[v[i]].second - s[i];
                    if(val % 2 == 1 || val <= 0){
                        ok = false;
                    }else{
                        ll aa = val / 2;
                        if(ans == -1){
                            ans = aa;
                        }else{
                            if(ans != aa) ok = false;
                        }
                    }
                }
            }
        }
        if(not ok){
            print(0);
        }else if(ans != -1){
            ll max_val = INF, min_val = -INF;
            rep(i,0,N){
                if(state[i].first == 0){
                    min_val = max(min_val, -state[i].second + 1);
                }else{
                    max_val = min(max_val, state[i].second - 1);
                }
            }
            if(ans >= min_val && ans <= max_val){
                print(1);
            }else{
                print(0);
            }
        }else{
            ll max_val = INF, min_val = -INF;
            rep(i,0,N){
                if(state[i].first == 0){
                    min_val = max(min_val, -state[i].second + 1);
                }else{
                    max_val = min(max_val, state[i].second - 1);
                }
            }
            // print(max_val, min_val);
            ll ans = max(0LL, max_val - min_val + 1);
            print(ans);
        }

    }


}