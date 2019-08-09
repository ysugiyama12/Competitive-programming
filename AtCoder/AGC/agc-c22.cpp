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
    ll N;
    cin >> N;
    ll a[55], b[55];
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];
    rep(i,0,N){
        if(a[i] != b[i] && (a[i] - 1)/2 < b[i]){
            print(-1);
            return 0;
        }
    }
    vector<ll> res;
    rrep(val,50,1){
        bool ok = true;
        vector<ll> use;
        rep(i,1,val) use.push_back(i);
        rep(i,0,res.size()) use.push_back(res[i]);
        vector<ll> tree[55];
        ll dist[55][55];
        rep(i,0,51){
            rep(j,0,51){
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }
        rep(i,0,51){
            for(auto &e: use){
                ll after = i % e;
                dist[i][after] = 0;
            }
        }
        rep(k,0,51){
            rep(i,0,51){
                rep(j,0,51){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        rep(i,0,N){
            if(dist[a[i]][b[i]] != 0) ok = false;
        }
        if(not ok) res.push_back(val);
    }
    ll ans = 0;
    for(auto &e: res) ans += pow(2, e);
    print(ans);



    
}