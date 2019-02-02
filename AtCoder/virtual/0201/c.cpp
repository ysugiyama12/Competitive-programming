#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll parent[200010];

ll root(ll x){
    if(x == parent[x]) return x;
    else return parent[x] = root(parent[x]);
}

void unite(ll a, ll b){
    a = root(a); b = root(b);
    if(a == b) return;
    parent[a] = b;
}

bool same(ll a, ll b){
    return root(a) == root(b);
}
typedef struct {
    ll to;
    ll c;
} ee;
typedef struct {
    ll to;
    ll cost;
} ee2;
ll N,M;
ll p[200010], q[200010], c[200010];
map<lpair, ll> mp;
vector<ee> tree[100010];
vector<ee2> tree2[1000010];
ll is_visit[1000010] = {};
ll dist[1000010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> p[i] >> q[i] >> c[i];
        p[i]--; q[i]--;
        ee tmp1 = {q[i], c[i]};
        tree[p[i]].push_back(tmp1);
        ee tmp2 = {p[i], c[i]};
        tree[q[i]].push_back(tmp2);
    }
    rep(i,0,N) parent[i] = i;
    rep(i,0,M){
        unite(p[i], q[i]);
    }
    if(!same(0,N-1)){
        print(-1);
        return 0;
    }
    rep(i,0,N){
        mp[make_pair(i, -1)] = i;
    }
    ll idx = N;
    rep(i,0,N){
        map<ll,ll> tt;
        for(auto &e: tree[i]){
            if(tt[e.c] != 0) continue;
            tt[e.c]++;
            mp[make_pair(i, e.c)] = idx;
            idx++;
        }
    }
    rep(i,0,N){
        map<ll,ll> tt;
        for(auto &e: tree[i]){
            if(tt[e.c] != 0) continue;
            tt[e.c]++;
            ee2 v = {mp[make_pair(i, e.c)], 1};
            tree2[mp[make_pair(i,-1)]].push_back(v);
            ee2 v2 = {i, 0};
            tree2[mp[make_pair(i, e.c)]].push_back(v2);
        }
    }
    // rep(i,0,N){
    //     print(i);
    //     rep(j,0,tree2[i].size()){
    //         print2(tree2[i][j].to, tree2[i][j].cost);
    //     }
    // }
    rep(i,0,M){
        ee2 v = {mp[make_pair(q[i], c[i])], 0};
        tree2[mp[make_pair(p[i], c[i])]].push_back(v);
        ee2 v2 = {mp[make_pair(p[i], c[i])], 0};
        tree2[mp[make_pair(q[i], c[i])]].push_back(v2);
    }
    // for(auto &e: mp){
    //     print(e.second);
    //     print2(e.first.first, e.first.second);
    // }
    // print("---");
    // rep(i,0,idx){
    //     print(i);
    //     rep(j,0,tree2[i].size()){
    //         print2(tree2[i][j].to, tree2[i][j].cost);
    //     }
    // }

    priority_queue< lpair, vector< lpair >, greater< lpair > > pq;
    rep(i,0,idx){
        dist[i] = INF;
    }
    dist[0] = 0;
    ll nidx = idx - 1;
    rep(i,0,nidx){
        pq.push(make_pair(dist[i], i));
    }
    while(!pq.empty()){
        auto tt = pq.top();
        pq.pop();
        is_visit[tt.second] = 1;
        for(auto &e : tree2[tt.second]){
            if(dist[e.to] > dist[tt.second] + e.cost){
                if(!is_visit[e.to]){
                    dist[e.to] = dist[tt.second] + e.cost;
                    pq.push(make_pair(dist[e.to], e.to));
                }
            }
        }
    }
    ll ans = dist[mp[make_pair(N-1, -1)]];
    print(ans);


    
    // print(idx);


}
