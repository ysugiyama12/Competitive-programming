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
    ll H,W,N;
    cin >> H >> W >> N;
    ll a[100010], b[100010];
    rep(i,0,N){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    ll cnt[11] = {};
    map<lpair, ll> mp;
    vector<lpair> lp;
    rep(i,0,N){
        rep(j,0,3){
            rep(k,0,3){
                if(a[i] - 1 + j >= 1 && a[i] - 1 + j <= H - 2 && b[i] - 1 + k >= 1 && b[i] - 1 + k <= W - 2){
                    mp[make_pair(a[i] - 1 + j, b[i] - 1 + k)]++;
                    if(mp[make_pair(a[i] - 1 + j, b[i] - 1 + k)] == 1){
                        lp.push_back(make_pair(a[i] - 1 + j, b[i] - 1 + k));
                    }
                }
            }
        }
    }
    ll cnt_0 = 0;
    rep(i,0,lp.size()){
        ll val = mp[lp[i]];
        cnt[val]++;
        cnt_0++;
    }
    cnt[0] = (H - 2) * (W - 2) - cnt_0;
    rep(i,0,10){
        print(cnt[i]);
    }


}
