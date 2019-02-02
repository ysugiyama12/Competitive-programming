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
typedef struct {
    ll u;
    ll v;
    ll cost;
} edge;

typedef struct {
    ll x;
    ll y;
    ll idx;
} edge2;

bool compx(edge2 l1, edge2 l2){
    return l1.x < l2.x;
}

bool compy(edge2 l1, edge2 l2){
    return l1.y < l2.y;
}

bool comp(edge l1, edge l2){
    return l1.cost < l2.cost;
}

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll x[100010], y[100010];
    cin >> N;
    rep(i,0,N) cin >> x[i] >> y[i];
    if(N == 2){
        print(min(abs(x[0]-x[1]), abs(y[0]-y[1])));
        return 0;
    }
    vector<edge2> lp;
    rep(i,0,N){
        edge2 e = {x[i], y[i], i};
        lp.push_back(e);
    }
    sort(lp.begin(), lp.end(), compx);
    vector<edge> ee;
    rep(i,1,N-1){
        edge tt = {lp[i-1].idx, lp[i].idx, abs(lp[i-1].x - lp[i].x)};
        ee.push_back(tt);
        edge tt2 = {lp[i+1].idx, lp[i].idx, abs(lp[i+1].x - lp[i].x)};
        ee.push_back(tt2);
    }
    sort(lp.begin(), lp.end(), compy);
    rep(i,1,N-1){
        edge tt = {lp[i-1].idx, lp[i].idx, abs(lp[i-1].y - lp[i].y)};
        ee.push_back(tt);
        edge tt2 = {lp[i+1].idx, lp[i].idx, abs(lp[i+1].y - lp[i].y)};
        ee.push_back(tt2);
    }
    sort(ee.begin(), ee.end(), comp);
    rep(i,0,N) parent[i] = i;
    ll ans = 0;
    for(auto &e: ee){
        ll u = e.u;
        ll v = e.v;
        ll cost = e.cost;
        if(same(u,v)) continue;
        unite(u,v);
        ans += cost;
    }
    print(ans);
    
    
    
}
