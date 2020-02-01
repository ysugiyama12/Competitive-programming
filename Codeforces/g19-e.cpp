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
ll dist[1010][1010] = {};
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
UnionFind uf(1010);
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[1010], y[1010];
    rep(i,0,N) cin >> x[i] >> y[i];
    map<ll,ll> mp[1010];
    map<ll,ll> mp2;
    rep(i,0,N){
        rep(j,0,N){
            dist[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            mp[i][dist[i][j]]++;
            if(i < j) mp2[dist[i][j]]++;
        }
    }
    rep(i,0,N){
        bool check = true;
        rep(j,0,N){
            if(i == j) continue;
        }
    }
    // ll sz = N;
    // rep(i,0,N){
    //     vector<ll> tt;
    //     rep(j,0,N){
    //         if(i == j) continue;
    //         if(mp[i][dist[i][j]] >= 2){
    //             tt.push_back(j);
    //         }
    //     }
    //     if(tt.size() >= 2){
    //         rep(i,0,tt.size()-1){
    //             if(not uf.same(tt[i], tt[i+1])){
    //                 sz--;
    //                 uf.unite(tt[i], tt[i+1]);
    //                 // print(tt[i], tt[i+1]);
    //             }
    //         }
    //     }
    // }
    // // print(sz);
    // rep(i,0,N){
    //     rep(j,i+1,N){
    //         if(not uf.same(i,j)){
    //             if(sz != 2){
    //                 uf.unite(i,j);
    //                 sz--;
    //             }
    //         }
    //     }
    // }
    // vector<ll> ans;
    // rep(i,0,N){
    //     if(uf.same(0,i)){
    //         ans.push_back(i+1);
    //     }
    // }
    // if(ans.size() == N){
    //     UnionFind uf2(1010);
    //     vector<lpair> alt;
    //     for(auto &e: mp2){
    //         if(e.second >= 2) alt.push_back({e.second, e.first});
    //     }
    //     sort(alt.begin(), alt.end(), less<lpair>());
    //     for(auto &e: alt){
    //         ll types[1010] = {};
    //         bool ok = true;
    //         rep(i,0,N){
    //             if(types[i] == 0) types[i] = 1;
    //             rep(j,0,N){
    //                 if(dist[i][j] == e.second){
    //                     if(types[j] == 0){
    //                         types[j] = (types[i] == 1 ? 2 : 1);
    //                     }else if(types[i] == types[j]){
    //                         ok = false;
    //                     }
    //                 }
    //             }
    //         }
    //         rep(i,0,N){
    //             rep(j,0,N){
    //                 if(types[i] == types[j]) uf2.unite(i,j);
    //             }
    //         }
    //         if(not ok) continue;
    //         vector<ll> v1,v2;
    //         map<ll,ll> mpa,mpb;
    //         rep(i,0,N){
    //             rep(j,i+1,N){
    //                 if(uf2.same(i,j)) mpa[dist[i][j]]++;
    //                 else mpb[dist[i][j]]++;
    //             }
    //         }
    //         for(auto &f: mpa){
    //             if(mpb[f.first]  > 0) ok = false;
    //         }
    //         if(ok){
    //             vector<ll> res;
    //             rep(i,0,N){
    //                 if(types[i] == 1) res.push_back(i+1);
    //             }
    //             print(res.size());
    //             printa(res, res.size());
    //             return 0;
    //         }
    //         // printa(types, N);
    //     }

    // }
    // print(ans.size());
    // printa(ans, ans.size());
    // vector<ll> v1,v2;
    // UnionFind uf2(1010);
    // uf2.unite(1,3);
    // uf2.unite(2,4);
    // uf2.unite(0,2);
    // rep(i,0,N){
    //     rep(j,i+1,N){
    //         if(uf2.same(i,j)) v1.push_back(dist[i][j]);
    //         else v2.push_back(dist[i][j]);
    //     }
    // }
    // printa(v1, v1.size());
    // printa(v2, v2.size());

    


    

}