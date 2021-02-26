#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;
typedef pair<li, li> pt;

const int N = 500010;

int n;
pt a[N];
vector<int> g[N];
bool used[N];

void dfs(int v, int p = -1) {
	used[v] = true;
	for (auto to : g[v]) if (to != p) {
		if (!used[to])
			dfs(to, v);
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d%d", &a[i].x, &a[i].y);
	
	vector<pt> evs;
	forn(i, n) {
		evs.pb(mp(a[i].x, i));
		evs.pb(mp(a[i].y, i));
	}
	
	sort(all(evs));
	
	int cnt = 0;
	set<pt> cur;
	for (auto it : evs) {
		if (cnt >= n) break;
		if (cur.count(it)) {
			cur.erase(it);
		} else {
			int i = it.y;
			int r = a[i].y;
			for (auto jt : cur) {
				if (jt.x > r) break;
				int j = jt.y;
				g[i].pb(j);
				g[j].pb(i);
				cnt++;
				if (cnt >= n) break;
			}
			cur.insert(mp(a[i].y, i));
		}
	}
	
	dfs(0);
	puts(cnt == n - 1 && count(used, used + n, 1) == n ? "YES" : "NO");
}