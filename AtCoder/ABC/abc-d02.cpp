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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll x[100], y[100];
    rep(i,0,M){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    ll tree[15][15] = {};
    rep(i,0,M){
        tree[x[i]][y[i]] = 1;
        tree[y[i]][x[i]] = 1;
    }
    ll ans = 0;
    rep(bit,0,pow(2,N)){
        bool ok = true;
        rep(i,0,N){
            rep(j,0,N){
                if(((bit >> i) & 1) && ((bit >> j) & 1) && i != j && i < j){
                    if(tree[i][j] != 1){
                        ok = false;
                    }

                }
            }
        }
        if(ok){
            ll cnt = 0;
            rep(i,0,N){
                if((bit >> i) & 1) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    print(ans);
}
