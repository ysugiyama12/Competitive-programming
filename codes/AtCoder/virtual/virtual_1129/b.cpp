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
    ll N,M;
    ll x[100010], y[100010];
    cin >> N >> M;
    rep(i,0,M){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    ll ans = 0;
    ll is_red[100010] = {};
    is_red[0] = 1;
    ll cnt[100010] = {};
    rep(i,0,N){
        cnt[i] = 1;
    }
    rep(i,0,M){
        if(is_red[x[i]] == 1){
            if(cnt[x[i]] == 1){
                is_red[x[i]] = 0;
                is_red[y[i]] = 1;
                cnt[x[i]]--;
                cnt[y[i]]++;
            }else{
                is_red[y[i]] = 1;
                cnt[x[i]]--;
                cnt[y[i]]++;
            }
        }else{
            cnt[x[i]]--;
            cnt[y[i]]++;
        }
    }
    rep(i,0,N){
        if(is_red[i] == 1) ans++;
    }
    print(ans);
}
