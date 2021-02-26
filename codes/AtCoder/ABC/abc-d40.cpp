#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll parent[100010] = {};
ll cnt[100010] = {};
ll N,M;
ll a[200010], b[200010], y[200010];
ll Q;
ll v[100010], w[100010];
ll ans[100010] = {};
vector< pair<ll, lpair > > tree;
vector< pair<ll, lpair> > qp;

ll root(ll x){
    if(x == parent[x]){
        return x;
    }else{
        return parent[x] = root(parent[x]);
    }
}

void unite(ll a, ll b){
    a = root(a);
    b = root(b);
    if(a == b){
        return;
    }
    cnt[a] = cnt[a] + cnt[b];
    cnt[b] = cnt[a];
    parent[a] = b;
}

bool comp(pair<ll, lpair> v1, pair<ll, lpair> v2){
    if(v1.second.first == v2.second.first){
        return v1.first < v2.first;
    }
    return v1.second.first > v2.second.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i] >> y[i];
        a[i]--; b[i]--;
        tree.push_back(make_pair(y[i], make_pair(a[i], b[i])));
    }
    sort(tree.begin(), tree.end(),greater< pair<ll, lpair> >());

    cin >> Q;
    rep(i,0,Q){
        cin >> v[i] >> w[i];
        v[i]--;
        qp.push_back(make_pair(i, make_pair(w[i], v[i])));
    }
    sort(qp.begin(), qp.end(), comp);

    rep(i,0,N){
        cnt[i] = 1;
        parent[i] = i;
    }
    ll idx = 0;
    rep(i,0,Q){
        ll year = qp[i].second.first;
        while(year < tree[idx].first && idx <= M-1){
            ll aa = tree[idx].second.first;
            ll bb = tree[idx].second.second;
            unite(aa, bb);
            idx++;
        }
        ll pos = qp[i].second.second;
        ans[qp[i].first] = cnt[root(pos)];
    }
    rep(i,0,Q){
        print(ans[i]);
    }

}
