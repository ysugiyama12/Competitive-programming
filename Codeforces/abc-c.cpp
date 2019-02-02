#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll h[110];
    cin >> N;
    rep(i,0,N) cin >> h[i];
    ll ans = 0;
    while(1){
        ll ps = 0;
        bool is_end = true;
        rep(i,0,N){
            if(h[i] == 0){
                ll min_val = INF;
                rep(j,ps,i){
                    min_val = min(min_val, h[j]);
                }
                if(min_val == INF){
                    ps = i+1;
                    continue;
                }
                rep(j,ps,i){
                    h[j] -= min_val;
                }
                ans += min_val;
                ps = i+1;
            }else{
                is_end = false;
            }
        }
        if(is_end) break;
        ll min_val = INF;
        rep(i,ps,N){
            min_val = min(min_val, h[i]);
        }
        if(min_val == INF) continue;
        rep(i,ps,N){
            h[i] -= min_val;
        }
        ans += min_val;
    }
    print(ans);
}
