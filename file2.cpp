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
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void solve(){
    ll N;
    cin >> N;
    vll m(N);
    vector<string> a(N), b(N);
    rep(i,0,N){
        cin >> a[i] >> m[i] >> b[i];
    }
    map<string, ll> idx;
    map<ll, string> inv;
    vector<vector<lpair> > tree(N*2+10);
    ll cur = 1;
    rep(i,0,N){
        if(idx[a[i]] == 0){
            idx[a[i]] = cur;
            inv[cur] = a[i];
            cur++;
        }
        if(idx[b[i]] == 0){
            idx[b[i]] = cur;
            inv[cur] = b[i];
            cur++;
        }
        tree[idx[a[i]]].push_back({idx[b[i]], m[i]});
    }

    ll M = cur;
    vector<bool> visit(M+1, false);

    vector<vll> res(M+1, vll(M+1, -1));

    auto dfs = [&](auto dfs, ll cur, ll st, ll dst, ll val) -> void {
        // print(cur);
        if(visit[cur]) return;
        visit[cur] = true;
        if(cur == dst){
            res[st][dst] = val; 
        }
        for(auto &e: tree[cur]){
            if(not visit[e.first]) dfs(dfs, e.first, st, dst, val * e.second);
        }
    };

    rep(i,1,M){
        rep(j,1,M){
            if(i == j) continue;
            visit.assign(M+1, false);
            dfs(dfs, i, i, j, 1);
        }
    }
    ll max_val = 0;
    lpair pos;
    rep(i,1,M){
        rep(j,1,M){
            if(i == j) continue;
            if(chmax(max_val, res[i][j])){
                pos = {i,j};
            }
        }
    }
    cout << "1" << inv[pos.first] << "=" << max_val << inv[pos.second] << endl;


    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}