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
ll dist[200010] = {};
vector<lpair> tree[200010];
map<lpair, ll> mp, mp2;
ll K;
void dfs(ll cur, ll par){
    for(auto &e: tree[cur]){
        if(e.first == par) continue;
        dfs(e.first, cur);
        dist[cur] += dist[e.first];
        if(dist[e.first] % 2 == 0){
            mp[{cur, e.first}]++;
            mp[{e.first, cur}]++;
            // print(cur, e.first);
            // print(dist[e.first]);
        }
    }
    dist[cur]++;
}

void dfs2(ll cur, ll par){
    for(auto &e: tree[cur]){
        if(e.first == par) continue;
        mp2[{cur,e.first}] = min(dist[e.first], 2*K - dist[e.first]);
        mp2[{e.first, cur}] = min(dist[e.first], 2*K - dist[e.first]);
        dfs2(e.first, cur);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        cin >> K;
        rep(i,0,2*K) tree[i].clear();
        mp.clear();
        mp2.clear();
        rep(i,0,2*K) dist[i] = 0;
        rep(i,0,2*K-1){
            ll a,b,t;
            cin >> a >> b >> t;
            a--; b--;
            tree[a].push_back({b,t});
            tree[b].push_back({a,t});
        }
        dfs(0, -1);
        ll G = 0;
        rep(i,0,2*K){
            for(auto &e: tree[i]){
                if(mp[{i, e.first}] == 0) G += e.second;
            }
        }
        G /= 2;
        ll B = 0;
        dfs2(0, -1);
        // printa(dist, 2*K);
        // print("---");
        rep(i,0,2*K){
            for(auto &e: tree[i]){
                // print(i,e.first, e.second);
                B += e.second * mp2[{i, e.first}];
            }
        }
        B /= 2;
        print(G,B);

    }
    

}