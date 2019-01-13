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
ll N;
ll B[21];
vector<ll> tree[21];
ll dfs(ll pos){
    ll max_num = 0, min_num = 1e9;
    for(auto &e : tree[pos]){
        ll val = dfs(e);
        max_num = max(max_num, val);
        min_num = min(min_num, val);
    }
    // if(pos == 0){
    //     print(max_num);
    //     print(min_num);
    // }
    if(max_num == 0 && min_num == 1e9){
        return 1;
    }
    return max_num + min_num + 1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> B[i];
        B[i]--;
    }
    // printa(B, N-1);
    rep(i,0,N-1){
        tree[B[i]].push_back(i+1);
    }
    // rep(i,0,N-1){
    //     printa(tree[i], tree[i].size());
    // }
    ll ans = dfs(0);
    print(ans);

}
