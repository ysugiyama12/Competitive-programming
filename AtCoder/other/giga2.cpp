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
vector<ll> tree[100010];
ll dist[100010] = {};
ll child[100010] = {};
ll ans2 = 0;
void dfs(ll cur, ll par, ll d){
    dist[cur] = d;
    child[cur] = 1;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur, d+1);
        dist[cur] += dist[e];
        child[cur] += child[e];
    }
}
ll N,M;
void dfs2(ll cur, ll par, ll d){
    // print(cur+1, dist[cur]);
    ans2 += dist[cur];
    for(auto &e: tree[cur]){
        if(e == par) continue;
        ll diff = N - child[e];
        // print(diff);
        ll tmp = dist[e];
        ll tt = dist[cur] - (dist[e] - d * child[e]) + diff;
        dist[e] += tt;
        dist[e] -= child[e] * (d+1);
        dfs2(e, cur, d+1);
        dist[e] = tmp;
        // dfs2(e, cur);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll a[100010], b[100010];
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    if(M - N == -1){ //木の場合
        ll ans = 0;
        dfs(0, -1, 0);
        // printa(dist, N);
        // printa(child, N);
        dfs2(0, -1, 0);
        print(ans2/2);
        return 0;

    }
    if(N > 3000 || M > 3000) return 0;
    ll ans = 0;
    rep(n,0,N){
        priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
        // priority_queue<lpair, vector<lpair> ,compare > pq;
        ll dist[3010] = {};
        rep(i,0,N) dist[i] = INF;
        dist[n] = 0;
        rep(i,0,N) pq.push(make_pair(dist[i], i));
        while(!pq.empty()){
            lpair l1 = pq.top();
            pq.pop();
            for(auto &e: tree[l1.second]){
                if(dist[e] > dist[l1.second] + 1){
                    dist[e] = dist[l1.second] + 1;
                    pq.push(make_pair(dist[e], e));
                }
            }
        }
        rep(i,0,N){
            ans += dist[i];
        }    
    }
    print(ans/2);
    

}