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
    ll N,K,L;
    cin >> N >> K >> L;
    ll p[100010], q[100010], r[100010], s[100010];
    rep(i,0,K){
        cin >> p[i] >> q[i];
        p[i]--; q[i]--;
    }
    rep(i,0,L){
        cin >> r[i] >> s[i];
        r[i]--; s[i]--;
    }
    rep(i,0,N){
        parent[i] = i;
    }
    rep(i,0,K){
        unite(p[i], q[i]);
    }
    ll root_a[200010], root_b[200010];
    rep(i,0,N){
        root_a[i] = root(i);
    }
    rep(i,0,N){
        parent[i] = i;
    }
    rep(i,0,L){
        unite(r[i], s[i]);
    }
    rep(i,0,N){
        root_b[i] = root(i);
    }
    map<lpair,ll> mp;
    rep(i,0,N){
        mp[make_pair(root_a[i], root_b[i])]++;
    }
    rep(i,0,N){
        cout << mp[make_pair(root_a[i], root_b[i])];
        if(i != N-1) cout << " ";
    }
    cout << endl;

}
