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
    ll N;
    ll x[2010], y[2010];
    cin >> N;
    rep(i,0,N){
        cin >> x[i] >> y[i];
    }
    if(N >= 200) return 0;
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,N){
                if(i != j && j != k && k != i){
                    ll d[3] = {};
                    d[0] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                    d[1] = (x[k]-x[j])*(x[k]-x[j]) + (y[k]-y[j])*(y[k]-y[j]);
                    d[2] = (x[i]-x[k])*(x[i]-x[k]) + (y[i]-y[k])*(y[i]-y[k]);
                    sort(d,d+3);
                    if(d[2] == d[0] + d[1]){
                        ans2++;
                    }else if(d[2] < d[0] + d[1]){
                        ans1++;
                    }else{
                        ans3++;
                    }
                }
            }
        }
    }
    cout << ans1/6 << " " << ans2/6 << " " << ans3/6 << endl;

}
