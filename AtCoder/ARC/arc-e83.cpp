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
vector<ll> tree[1010];
multiset<ll> mt[1010];
ll P[1010], X[1010];

bool ok = true;
void dfs(ll cur, ll par) {
    if(tree[cur].size() == 0){
        mt[par].insert(X[cur]);
        return;
    }
    for(auto &e: tree[cur]) {
        dfs(e, cur);
    }
    auto iter = mt[cur].lower_bound(X[cur]);
    if(iter == mt[cur].begin()){
        ok = false;
        return;
    }
    iter--;
    mt[cur].erase(iter);
    mt[cur].insert(X[cur]);
    if(cur == 0) return;
    for(auto &e: mt[cur]){
        mt[par].insert(e);
    }

    // 2 3 5


}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N-1){
        cin >> P[i];
        P[i]--;
        tree[P[i]].push_back(i+1);
    }
    rep(i,0,N) cin >> X[i];
    dfs(0, -1);
    if(ok){
        print("POSSIBLE");
    }else{
        print("IMPOSSIBLE");
    }// 0 0 0 2 3 4 4

}