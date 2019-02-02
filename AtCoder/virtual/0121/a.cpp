#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll parent[200010];

ll root(ll x){
    if(x == parent[x]) return x;
    else return parent[x] = root(parent[x]);
}

void unite(ll a, ll b){
    a = root(a); b = root(b);
    if(a == b) return;
    parent[a] = b;
}

bool same(ll a, ll b){
    return root(a) == root(b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll K[100010];
    vector<ll> L[100010];
    cin >> N >> M;
    vector<ll> tree[100010];
    rep(i,0,N){
        cin >> K[i];
        rep(j,0,K[i]){
            ll tmp;
            cin >> tmp;
            tree[tmp].push_back(i);
            L[i].push_back(tmp);
        }
    }
    rep(i,0,N){
        parent[i] = i;
    }
    rep(i,1,M+1){
        ll n = tree[i].size();
        if(n == 1) continue;
        rep(j,0,n-1){
            unite(tree[i][j], tree[i][j+1]);
        }
    }
    bool ans = true;
    ll v = root(0);
    rep(i,1,N){
        if(root(i) != v) ans = false;
    }
    if(ans){
        print("YES");
    }else{
        print("NO");
    }




}
