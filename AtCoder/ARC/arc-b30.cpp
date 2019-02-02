#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll n,x;
ll h[110];
ll a[110], b[110];
vector<ll> tree[110];
bool d[110];
// ll dfs(ll cur, ll par){
//     if(tree[cur].size() == 1){
//         if(h[cur] == 1){
//             return 1;
//         }else{
//             return 0;
//         }
//     }
//     ll val = 0;
//     for(auto &e: tree[cur]){
//         if(e != par){
//             val += dfs(e,cur);
//         }
//     }
//     if(val == 0){
//         if(h[cur] == 1 && cur != x) val++;
//     }else{
//         if(cur != x) val++;
//     }
//     return val;
// }
void dfs(ll cur, ll par){
    if(h[cur] == 1) d[cur] = true;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
        if(d[e] == true) d[cur] = true;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> x;
    x--;
    rep(i,0,n){
        cin >> h[i];
    }
    rep(i,0,n-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    rep(i,0,n){
        d[i] = false;
    }
    dfs(x,-1);
    d[x] = true;
    ll ans = 0;
    rep(i,0,n-1){
        if(d[a[i]] && d[b[i]]) ans += 2;
    }
    print(ans);


}
