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
    ll N;
    ll C[110];
    cin >> N;
    rep(i,0,N){
        cin >> C[i];
    }
    double cnt[110] = {};
    rep(i,0,N){
        rep(j,0,N){
            if(i != j && C[i] % C[j] == 0){
                cnt[i]++;
            }
        }
    }
    // printa(cnt,N);
    double ans = 0;
    rep(i,0,N){
        if((int)cnt[i] % 2 == 0){
            ans += (cnt[i]+2)/(2*cnt[i] + 2);
        }else{
            ans += (double)1/2;
        }
    }
    cout << setprecision(10) << ans << endl;
}
