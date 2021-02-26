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
ll parent[200010];
ll cnt[200010];

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
    cnt[a] = cnt[a] + cnt[b];
    cnt[b] = cnt[a];
    parent[a] = b;
}

void same(ll a, ll b){
    if(root(a) == root(b)){
        print("Yes");
    }else{
        print("No");
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll a[110], b[110];
    rep(i,0,M){
        cin >> a[i] >> b[i];
    }
    rep(i,0,N){
        parent[i] = i;
        cnt[i] = 1;
    }
    rep(i,0,M){
        unite(a[i], b[i]);
    }
    rep(i,0,N){
        print(cnt[parent[i]]);
    }
}
