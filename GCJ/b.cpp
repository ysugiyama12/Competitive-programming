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
#define Case(t) cout << "Case #" << t << ": "

void solve(ll t){
    ll C,D;
    cin >> C >> D;
    ll X[110];
    vector<ll> tree[110];
    rep(i,1,C) cin >> X[i];
    rep(i,1,C){
        if(X[i] >= 0) return;
    }
    ll u[1010], v[1010];
    map<lpair, ll> mp;
    rep(i,0,D){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
        mp[{u[i],v[i]}] = i;
        mp[{v[i],u[i]}] = i;
    }

    ll dist[110] = {};
    rep(i,0,C) dist[i] = INF;
    dist[0] = 0;
    vector<lpair> lp;
    rep(i,1,C){
        lp.push_back({abs(X[i]), i});
    }
    sort(lp.begin(), lp.end());
    ll ans[1010] = {};

    ll prev_val = -1;
    ll prev_dist = -1;
    for(auto &e: lp){
        ll cur = e.second;
        ll n = e.first;
        // print(cur, prev_dist);
        if(prev_val == n){
            // print("aa");
            ll min_dist = INF;
            for(auto &e2: tree[cur]){
                min_dist = min(min_dist, dist[e2]);
            }
            // print(min_dist, prev_dist);
            if(prev_dist == -1){
                dist[cur] = 1;
                for(auto &e2: tree[cur]){
                    if(dist[e2] != INF){
                        ll idx = mp[{cur,e2}];
                        ans[idx] = 1;
                    }
                }
                prev_dist = 1;
            }else{
                // print(cur, prev_dist);
                dist[cur] = prev_dist;
                for(auto &e2: tree[cur]){
                    if(dist[e2] != INF){
                        ll idx = mp[{cur,e2}];
                        ans[idx] = prev_dist - min_dist;
                    }
                }  
            }
            prev_val = n;            

        }else{
            ll min_dist = INF;
            for(auto &e2: tree[cur]){
                min_dist = min(min_dist, dist[e2]);
            }
            if(prev_dist == -1){
                dist[cur] = 1;
                for(auto &e2: tree[cur]){
                    if(dist[e2] != INF){
                        ll idx = mp[{cur,e2}];
                        ans[idx] = 1;
                    }
                }
                prev_dist = 1;
            }else{
                // print(cur, prev_dist);
                dist[cur] = 1 + prev_dist;
                for(auto &e2: tree[cur]){
                    if(dist[e2] != INF){
                        ll idx = mp[{cur,e2}];
                        ans[idx] = 1 + prev_dist - min_dist;
                    }
                }
                prev_dist++;  
            }
            prev_val = n;
        }


    }
    Case(t);
    printa(ans, D);


    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    rep(i,1,t+1) solve(i);
}