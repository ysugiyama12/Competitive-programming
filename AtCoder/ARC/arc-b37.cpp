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
ll N,M;
ll u[110], v[110];
vector<ll> tree[110];
ll parent[200010];
ll is_check[110] = {};

ll root(ll x){
    if(x == parent[x]){
        return x;
    }else{
        return parent[x] = root(parent[x]);
    }
}

void unite(ll a, ll b){
    a = root(a);
    b = root(b);
    if(a == b){
        return;
    }
    parent[a] = b;
}

bool same(ll a, ll b){
    return root(a) == root(b);
}

void check(ll cur, ll par){
    if(is_check[cur] == 1)
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,N){
        parent[i] = i;
    }
    rep(i,0,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
        unite(u[i], v[i]);
    }
    memset(is_check,-1,sizeof(is_check));
    rep(i,0,N){
        if(is_check[i] == -1){
            rep(j,0,N){
                if(same(i,j)) is_check[j] = 0;
                check(i, -1);
            }

        }

    }


}
