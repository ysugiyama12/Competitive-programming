#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
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
ll N,M;
ll C[1010], B[1010];
ll pp[1010];
vector<ll> tree[1010];
ll ans_tmp = 0;
map<ll, ll> mp;
ll dfs(ll pos, ll parent){
    if(tree[pos].size() == 0) return mp[pos];
    if(parent == -1){
        ll vv = 0;
        for(auto &e : tree[pos]){
            ll v = dfs(e,pos);
            vv += v;
        }
        return vv;
    }else{
        ll ans = 0;
        ll min_val = 1e9;
        vector<ll> tmp;
        for(auto &e : tree[pos]){
            ll v = dfs(e,pos);
            tmp.push_back(v);
            min_val = min(min_val, v);
        }
        rep(i,0,tmp.size()){
            ans_tmp += (tmp[i] - min_val);
        }
        // ans_tmp += min_val;
        return min_val;

    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,1,N){
        cin >> pp[i];
    }
    rep(i,1,N){
        tree[pp[i]].push_back(i);
    }
    rep(i,0,M){
        cin >> B[i] >> C[i];
    }
    rep(i,0,M){
        mp[B[i]] = C[i];
    }
    // rep(i,0,N){
    //     rep(j,0,tree[i].size()){
    //         print(tree[i][j]);
    //     }
    //     print("--");
    // }
    ll ans = dfs(0, -1);
    // print(ans);
    // print(ans_tmp);
    print(ans + ans_tmp);

}
