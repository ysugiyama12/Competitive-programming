/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
void print() {}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail){ cout << head << " \n"[sizeof...(tail) == 0]; print(forward<Tail>(tail)...);}
bool seen[1010] = {}, finished[1010] = {};
ll N,M;
vector<ll> tree[1010];
ll pos = -1;
stack<ll> hist;

void dfs(ll cur, ll par){
    seen[cur] = true;
    hist.push(cur);
    for(auto &e: tree[cur]){
        if(e == par) continue;
        if(finished[e]) continue;

        if(seen[e] && !finished[e]){
            pos = e;
            return;
        }
        dfs(e, cur);
        if(pos != -1) return;
    }
    hist.pop();
    finished[cur] = true;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll A[2010], B[2010];
    ll h[1010] = {};
    map<lpair, ll> mp;
    rep(i,0,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        h[B[i]]++;
        mp[make_pair(A[i], B[i])]++;
    }
    pos = -1;
    dfs(0, -1);
    set<ll> cycle;
    vector<ll> dd;
    while (!hist.empty()) {
        ll t = hist.top();
        dd.push_back(t);
        cycle.insert(t);
        hist.pop();
        if (t == pos) break;
    }
    if(cycle.size() == 0){
        print(-1);
        return 0;
    }
    reverse(dd.begin(), dd.end());
    ll sz = dd.size();
    if(sz == 3){
        print(sz);
        for(auto &e: dd) print(e+1);
        return 0;
    }
    rep(diff, 1, sz/2 + 1){
        rep(i,0,sz){
            ll start = i, goal = (i+diff) % sz;
            if(mp[make_pair(dd[goal], dd[start])]){
                // print(start, goal);
                // print(dd[goal],dd[start]);
                print(diff+1);
                rep(j,i,i+diff+1){
                    print(dd[j % sz]+1);
                }
                return 0;
            }
        }
    }
    print(sz);
    for(auto &e: dd) print(e+1);

    
}
