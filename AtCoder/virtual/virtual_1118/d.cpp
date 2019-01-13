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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll W,H;
    ll p[100010], q[100010];
    cin >> W >> H;
    rep(i,0,W){
        cin >> p[i];
    }
    rep(i,0,H){
        cin >> q[i];
    }
    ll ans = 0;
    ll check_x = 0, check_y = 0;
    vector<lpair> v;
    rep(i,0,W){
        v.push_back(make_pair(p[i],0));
    }
    rep(i,0,H){
        v.push_back(make_pair(q[i],1));
    }
    sort(v.begin(), v.end());
    rep(i,0,H+W){
        ll val = v[i].first;
        if(v[i].second == 0){
            ans += val * (H+1-check_y);
            check_x++;
        }else{
            ans += val * (W+1-check_x);
            check_y++;
        }
    }
    print(ans);
}
