/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
vector<ll> tree[100010];
ll depth[100010] = {};
ll parent[100010] = {};
ll next_val[25][100010] = {};
ll logN = 0;

void dfs(ll cur, ll par, ll d){
    depth[cur] = d;
    parent[cur] = par;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur, d+1);
    }
}

ll get_parent(ll cur, ll num) {
    ll p = cur;
    rrep(k,logN-1, 0){
        if(p == -1){
            break;
        }
        if((num >> k) & 1){
            p = next_val[k][p];
        }
    }
    return p;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    logN = floor(log2(N)) + 1;
    rep(i,0,N-1){
        ll x,y;
        cin >> x >> y;
        x--; y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(0,-1, 0);
    rep(i,0,N){
        next_val[0][i] = parent[i];
    }
    rep(k,0,logN){
        rep(i,0,N){
            if(next_val[k][i] == -1){
                next_val[k+1][i] = -1;
            }else{
                next_val[k+1][i] = next_val[k][next_val[k][i]];
            }
        }
    }
    // rep(i,0,N) print(next_val[1][i]);
    ll Q;
    cin >> Q;
    while(Q--){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        ll va = a, vb = b;
        if(depth[va] > depth[vb]){
            va = get_parent(va, depth[va] - depth[vb]);
        }else if(depth[va] < depth[vb]){
            vb = get_parent(vb, depth[vb] - depth[va]);
        }
        ll lv = -1, rv = N+1;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            ll ta = get_parent(va, mid);
            ll tb = get_parent(vb, mid);
            if(ta == -1 || tb == -1){
                rv = mid;
            }else if(ta != tb){
                lv = mid;
            }else{
                rv = mid;
            }
        }
        ll ans = 2 * rv + abs(depth[a] - depth[b]) + 1;
        print(ans);


    }

}