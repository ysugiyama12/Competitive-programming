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
    ll R,C,K;
    cin >> R >> C >> K;
    string s[510];
    rep(i,0,R){
        cin >> s[i];
    }
    ll cnt = 0;
    ll cnt_up[510][510];
    rep(j,0,C){
        cnt = 0;
        rep(i,0,R){
            cnt_up[i][j] = cnt;
            if(s[i][j] == 'x'){
                cnt = 0;
            }else{
                cnt++;
            }

        }
    }
    ll cnt_down[510][510];
    rep(j,0,C){
        cnt = 0;
        rep(i,0,R){
            cnt_down[R-1-i][j] = cnt;
            if(s[R-1-i][j] == 'x'){
                cnt = 0;
            }else{
                cnt++;
            }

        }
    }
    ll ans = 0;
    rep(i,K-1,R-K+1){
        rep(j,K-1,C-K+1){
            bool is_ok = true;
            rep(k,j-K+1,j+K){
                ll max_val = K - 1;
                ll diff = abs(j - k);
                ll num = max_val - diff;
                if(cnt_up[i][k] < num || cnt_down[i][k] < num || s[i][k] == 'x') is_ok = false;
            }
            if(is_ok) ans++;
        }
    }
    print(ans);

}
