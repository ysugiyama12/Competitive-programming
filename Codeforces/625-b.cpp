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
ll u[200010], v[200010];
vector<ll> tree[200010];
vector<ll> tree_inv[200010];
ll p[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;

    rep(i,0,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[v[i]].push_back(u[i]);
        tree_inv[u[i]].push_back(v[i]);
    }
    ll K;
    cin >> K;

    rep(i,0,K){
        cin >> p[i];
        p[i]--;
    }

    priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
    
    // priority_queue<lpair, vector<lpair> ,compare > pq;
    ll dist[200010] = {};
    rep(i,0,N) dist[i] = INF;
    dist[p[K-1]] = 0;
    pq.push({0,p[K-1]});
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        if(dist[l1.second] < l1.first) continue;
        for(auto &e: tree[l1.second]){
            if(dist[e] > dist[l1.second] + 1){
                dist[e] = dist[l1.second] + 1;
                pq.push(make_pair(dist[e], e));
            }
        }
    }
    ll ans_min = 0, ans_max = 0;
    rep(i,0,K-1){
        if(dist[p[i]] <= dist[p[i+1]]){
            ans_min++;
            ans_max++;
        }else{
            ll v = dist[p[i+1]];
            ll cnt = 0;
            for(auto &e: tree_inv[p[i]]){
                if(v == dist[e]){
                    cnt++;
                }
            }
            if(cnt >= 2){
                ans_max++;
            }
        }
    }
    print(ans_min, ans_max);


}