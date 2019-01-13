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
vector<ll> v_r[100010];
vector<ll> v_c[100010];
ll cnt_r[100010] = {}, cnt_c[100010] = {};
ll num_r[100010] = {}, num_c[100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R,C,K,N;
    ll r[100010], c[100010];
    cin >> R >> C >> K;
    cin >> N;
    rep(i,0,N){
        cin >> r[i] >> c[i];
    }
    rep(i,0,N){
        cnt_r[r[i]-1]++;
        cnt_c[c[i]-1]++;
    }
    // rep(i,0,N){
    //     v_r[r[i]].push_back(c[i]);
    //     v_c[c[i]].push_back(r[i]);
    // }
    // printa(cnt_r, 10);
    // printa(cnt_c, 10);
    rep(i,0,R){
        num_r[cnt_r[i]]++;
    }
    rep(i,0,C){
        num_c[cnt_c[i]]++;
    }
    // printa(num_r, 10);
    // printa(num_c, 10);
    ll ans = 0;
    rep(i,0,K+1){
        ans += num_r[i] * num_c[K - i];
    }
    rep(i,0,N){
        if(cnt_r[r[i]-1] + cnt_c[c[i]-1] == K){
            ans--;
        }else if(cnt_r[r[i]-1] + cnt_c[c[i]-1] == K+1){
            ans++;
        }
    }
    print(ans);
}
