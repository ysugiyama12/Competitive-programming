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

bool comp(lpair l1, lpair l2){
    if(l1.second == l2.second){
        return l1.first < l2.first;
    }
    return l1.second < l2.second;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll a[100010];
    ll x[100010], y[100010];
    cin >> N >> M;
    rep(i,0,N){
        cin >> a[i];
    }
    rep(i,0,M){
        cin >> x[i] >> y[i];
    }

    rep(i,0,N){
        parent[i] = i;
    }
    rep(i,0,M){
        unite(x[i], y[i]);
    }

    if(M == N-1){
        print(0);
        return 0;
    }
    ll num = 2 * (N - 1 - M);
    if(num > N){
        print("Impossible");
        return 0;
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(a[i], root(i)));
    }
    sort(lp.begin(), lp.end(), comp);
    ll ans = 0;
    ans += lp[0].first;
    vector<ll> lp2;
    rep(i,1,N){
        if(lp[i-1].second != lp[i].second){
            ans += lp[i].first;
        }else{
            lp2.push_back(lp[i].first);
        }
    }
    sort(lp2.begin(), lp2.end());
    rep(i,0,N-M-2){
        ans += lp2[i];
    }
    print(ans);





}
