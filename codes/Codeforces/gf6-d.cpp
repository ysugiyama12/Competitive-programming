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
vector<lpair> tree_inv[100010];
ll u[300010], v[300010], d[300010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    map<lpair, ll> exists;
    rep(i,0,M){
        cin >> u[i] >> v[i] >> d[i];
        u[i]--; v[i]--;
        if(exists[{u[i], v[i]}]){
            ll sum = exists[{u[i], v[i]}] + d[i];
            exists[{u[i], v[i]}] += d[i];
        }else{
            exists[{u[i],v[i]}] = d[i];
        }
        // tree[u[i]].push_back({v[i], d[i]});
        // tree_inv[v[i]].push_back({u[i], d[i]});
    }
    for(auto &e: exists){
        lpair vertex = e.first;
        ll dist = e.second;
        tree[vertex.first].push_back({vertex.second, dist});
        tree_inv[vertex.second].push_back({vertex.first, dist});
    }

    map<lpair,ll> mp, mp_inv;
    rep(i,0,N){
        for(auto &e: tree[i]){
            mp[{i, e.first}] = e.second;
            // print(e);
        }
        for(auto &e: tree_inv[i]){
            mp_inv[{e.first,i}] = e.second;
        }
    }
    rep(i,0,N){
        ll cnt1 = 0, cnt2 = 0;
        vector<lpair> v1, v2;
        for(auto &e: tree[i]){
            if(mp[e] > 0){
                cnt1++;
                v1.push_back(e);
            }
        }
        for(auto &e: tree_inv[i]){
            if(mp_inv[e] > 0){
                cnt2++;
                v2.push_back(e);
            }
        }
        ll mm = min(v1.size(), v2.size());
        // print(i,mm);
        rep(j,0,mm){
            ll min_val = min(mp[v1[j]], mp_inv[v2[j]]);
            mp[{v2[j].first, v1[j].first}] += min_val;
            mp_inv[{v1[j].first, v2[j].first}] += min_val;
            mp[v1[j]] -= min_val;
            mp_inv[v2[j]] -= min_val;
        }

        // ll min_val = INF;
        // for(auto &e: tree[i]){
        //     if(mp[e] > 0) min_val = min(min_val, mp[e]);
        // }
        // ll min_val2 = INF;
        // for(auto &e: tree_inv[i]){
        //     if(mp_inv[e] > 0) min_val2 = min(min_val2, mp_inv[e]);
        // }
        // if(min_val == INF || min_val2 == INF) continue;
        // ll diff = min(min_val, min_val2);
        // if(min_val == diff){

        // }
    }
    for(auto &e: mp){
        if(e.second > 0){
            print(e.first.first+1, e.first.second+1, e.second);
        }
    }

    

}