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
ll X[200010], Y[200010];
ll H,W,N;
map<lpair, ll> mp;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> N;
    rep(i,0,N){
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
    }
    // char c[20][20];
    // rep(i,0,H){
    //     rep(j,0,W){
    //         c[i][j] = '.';
    //     }
    // }
    // rep(i,0,N){
    //     c[X[i]][Y[i]] = '#';
    // }
    // rep(i,0,H){
    //     rep(j,0,W){
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }
    map<lpair, ll> mp;
    rep(i,0,N){
        mp[make_pair(X[i], Y[i])] = 1;
    }
    ll pos[200010] = {};
    ll is_check[200010] = {};
    ll py = 0;
    rep(i,0,H-1){
        if(mp[make_pair(i+1,  py)] == 1){
            // print(i);
            pos[py] = i;
            is_check[py] = 1;
            break;
        }
        if(mp[make_pair(i+1, py+1)] == 0){
            pos[py] = i+1;
            is_check[py] = 1;
            py++;
        }
        // if(mp[make_pair(i, py+1)] == 1 && mp[make_pair(i+1, py)] == 1){
        //     pos[py] = i;
        //     break;
        // }else if(mp[make_pair(i+1, py)] == 1){
        //     pos[py] = i;
        //     break;
        // }else if(mp[make_pair(i, py+1)] == 1){
        //     pos[py] = i;
        // }else{
        //     pos[py++] = i;
        // }
        // cout << i << " " << py << endl;
    }
    // printa(pos, W);
    ll ans = H;
    rep(i,0,N){
        if(pos[Y[i]] < X[i] && is_check[Y[i]] != 0){
            ans = min(ans, X[i]);

        }
    }
    print(ans);

}
