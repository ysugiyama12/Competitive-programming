#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll N;
ll p[100010];
ll s[100010];
bool ok = true;
vector<ll> tree[100010];

void dfs(ll cur){
    if(tree[cur].size() == 0) return;
    if(s[cur] == -1){
        ll mv = INF;
        for(auto &e: tree[cur]){
            dfs(e);
            if(s[e] != -1){
                mv = min(mv, s[e]);
            }
        }
        if(mv == INF){
            mv = 0;
        }
        for(auto &e: tree[cur]){
            if(s[e] == -1){
                s[e] = 0;
            }else{
                s[e] -= mv;
            }
        }
        s[cur] = mv;

    }else{
        for(auto &e: tree[cur]){
            dfs(e);
            if(s[e] != -1 && s[cur] > s[e]){
                ok = false;
                return;
            }
            if(s[e] == -1){
                s[e] = 0;
            }else{
                s[e] -= s[cur];
            }
        }

    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> p[i];
        p[i]--;
        tree[p[i]].push_back(i+1);
    }
    rep(i,0,N){
        cin >> s[i];
    }
    dfs(0);
    ll ans = 0;
    rep(i,0,N){
        ans += s[i];
    }
    if(ok){
        print(ans);
    }else{
        print(-1);
    }
}
