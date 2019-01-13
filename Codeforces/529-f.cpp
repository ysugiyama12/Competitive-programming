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

bool same(ll a, ll b){
    if(root(a) == root(b)){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll a[200010];
    rep(i,0,N){
        cin >> a[i];
    }
    ll x[200010], y[200010], w[200010];
    rep(i,0,M){
        cin >> x[i] >> y[i] >> w[i];
        x[i]--; y[i]--;
    }
    rep(i,0,N){
        parent[i] = i;
    }
    vector< pair<ll, lpair> > lp;
    ll pos = -1;
    ll val = INF;
    rep(i,0,N){
        if(val > a[i]){
            pos = i;
            val = a[i];
        }
    }
    rep(i,0,N){
        if(i != pos){
            lp.push_back(make_pair(val+a[i], make_pair(pos, i)));
        }
    }
    rep(i,0,M){
        lp.push_back(make_pair(w[i], make_pair(x[i], y[i])));
    }
    ll n = lp.size();
    sort(lp.begin(), lp.end());
    // print("--");
    // rep(i,0,n){
    //     cout << lp[i].first << " " <<  lp[i].second.first << " " << lp[i].second.second << endl;
    // }
    ll ans = 0;
    rep(i,0,n){
        ll pts = lp[i].first;
        ll pa = lp[i].second.first;
        ll pb = lp[i].second.second;
        if(same(pa,pb)) continue;
        unite(pa, pb);
        ans += pts;

    }
    print(ans);
    // vector< pair<ll, lpair> > xy;
    // rep(i,0,M){
    //     xy.push_back(make_pair(w[i], make_pair(x[i], y[i])));
    // }
    // sort(xy.begin(), xy.end());

    // // ll ans = 0;
    // ll min_val = INF, min_pos = -1;
    // rep(i,0,N){
    //     if(min_val > a[i]){
    //         min_val = a[i];
    //         min_pos = i;
    //     }
    // }
    // vector<lpair> lp;
    // rep(i,0,N){
    //     lp.push_back(make_pair(a[i], i));
    // }
    // sort(lp.begin(), lp.end());
    // ll cnt = 0;
    // ll ans = 0;
    // ll idx1 = 1, idx2 = 0;
    // while(cnt < N-1){
    //     if(lp[idx1].first < xy[idx2].first){
    //         if(root(lp[idx1].second) == root(min_pos)){
    //             idx1++;
    //         }
    //         ans += 
    //     }else{

    //     }


    // }
    // rep(i,0,N){
    //     if(i != min_pos){
    //         ans += a[i] + a[min_pos];
    //     }
    // }
    // print(ans);
    
    
}
