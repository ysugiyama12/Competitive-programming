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
    ll weigh;
    ll u;
    ll v;
} tree;

bool comp(tree t1, tree t2){
    return t1.weigh < t2.weigh;
}
ll N,M;
ll u[200010], v[200010], w[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
    }
    vector<tree> lp;
    rep(i,0,M){
        tree t = {w[i], u[i], v[i]};
        lp.push_back(t);
    }
    sort(lp.begin(), lp.end(), comp);
    rep(i,0,N){
        parent[i] = i;
    }
    ll ans = 0;
    rep(i,0,M){
        if(!same(lp[i].u, lp[i].v)){
            unite(lp[i].u, lp[i].v);
        }else{
            if(lp[i].weigh == lp[i-1].weigh && (lp[i].u == lp[i-1].u || lp[i].v == lp[i-1].u ||lp[i].u == lp[i-1].v ||lp[i].v == lp[i-1].v)){
                ans++;
            }
        }

    }
    print(ans);


}
