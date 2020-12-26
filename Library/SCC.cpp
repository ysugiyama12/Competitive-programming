/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

using UnWeightedGraph = vector<vll>;
template< typename G >
struct SCC {
	const G &g;
	UnWeightedGraph gg, rg;
	vll comp, order, used;

	SCC(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
		for(int i = 0; i < g.size(); i++) {
			for(auto e : g[i]) {
				gg[i].emplace_back((int) e);
				rg[(int) e].emplace_back(i);
			}
		}
	}

	int operator[](int k) {
		return comp[k];
	}

	void dfs(int idx) {
		if(used[idx]) return;
		used[idx] = true;
		for(int to : gg[idx]) dfs(to);
		order.push_back(idx);
	}

	void rdfs(int idx, int cnt) {
		if(comp[idx] != -1) return;
		comp[idx] = cnt;
		for(int to : rg[idx]) rdfs(to, cnt);
	}

	void build(UnWeightedGraph &t) {
		for(int i = 0; i < gg.size(); i++) dfs(i);
		reverse(begin(order), end(order));
		int ptr = 0;
		for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

		t.resize(ptr);
		for(int i = 0; i < g.size(); i++) {
			for(auto &to : g[i]) {
				int x = comp[i], y = comp[to];
				if(x == y) continue;
				t[x].push_back(y);
			}
		}
	}
};


void solve(){
	ll V,E;
	cin >> V >> E;
	UnWeightedGraph g(V);
	rep(i,0,E){
		ll s,t;
		cin >> s >> t;
		g[s].push_back(t);
	}
	SCC scc(g);
	UnWeightedGraph tree;
	scc.build(tree);

	ll Q;
	cin >> Q;
	while(Q--){
		ll a,b;
		cin >> a >> b;
		if(scc[a] == scc[b]){
			print(1);
		}else{
			print(0);
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}