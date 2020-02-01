/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

// Lowest Common Ancestor
vector<int> tree[100010];
int parent[100010] = {};
int depth[100010] = {};
int next_val[25][100010] = {};
ll logN = 0;
ll N;

void dfs(ll cur, ll par, ll d){
	depth[cur] = d;
	parent[cur] = par;
	for(auto &e: tree[cur]){
		if(e == par) continue;
		dfs(e, cur, d+1);
	}
}


ll getParent(ll cur, ll num) {
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

ll getLCA(ll va, ll vb){
	if(depth[va] > depth[vb]){
		va = getParent(va, depth[va] - depth[vb]);
	}else if(depth[va] < depth[vb]){
		vb = getParent(vb, depth[vb] - depth[va]);
	}
	ll lv = -1, rv = N+1;
	while(rv - lv > 1){
		ll mid = (rv + lv) / 2;
		ll ta = getParent(va, mid);
		ll tb = getParent(vb, mid);
		if(ta == -1 || tb == -1){
			rv = mid;
		}else if(ta != tb){
			lv = mid;
		}else{
			rv = mid;
		}
	}
	return getParent(va, rv);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	rep(i,0,N-1){
		ll u,v;
		cin >> u >> v;
		u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	logN = floor(log2(N)) + 1;
	dfs(0, -1, 0);
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
	ll Q;
	cin >> Q;
	while(Q--){
		ll a,b;
		cin >> a >> b;
		a--; b--;
		ll pa = getLCA(a,b);
		ll dd = depth[a] - depth[pa] + depth[b] - depth[pa] + 1;
		print(dd);
	}
}