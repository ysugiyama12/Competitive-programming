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
    double K;
    cin >> K;
    ll v1 = 200 / K;
    double px = 100;
    double py = 100;
    ll ans1 = 0;
    rep(i,0,v1){
        rep(j,0,v1){
            double ii = i;
            double jj = j;
            bool is_ok = true;
            // print((ii*K - px) * (ii*K - px) + (jj*K- py) * (jj*K - py));
            if((ii*K - px) * (ii*K - px) + (jj*K - py) * (jj*K - py) > 100*100){
                is_ok = false;
            }
            if(((ii+1)*K - px) * ((ii+1)*K - px) + (jj*K - py) * (jj*K - py) > 100*100){
                is_ok = false;
            }
            if((ii*K - px) * (ii*K - px) + ((jj+1)*K - py) * ((jj+1)*K - py) > 100*100){
                is_ok = false;
            }
            if(((ii+1)*K - px) * ((ii+1)*K - px) + ((jj+1)*K - py) * ((jj+1)*K - py) > 100*100){
                is_ok = false;
            }
            if(is_ok){
                ans1++;
            }
        }
    }
    ll v2 = 300/K;
    ll ans2 = 0;
    px = 150;
    py = 150;
    rep(i,0,v2){
        rep(j,0,v2){
            double ii = i;
            double jj = j;
            bool is_ok = true;
            // print((ii*K - px) * (ii*K - px) + (jj*K- py) * (jj*K - py));
            if((ii*K - px) * (ii*K - px) + (jj*K - py) * (jj*K - py) > 150*150){
                is_ok = false;
            }
            if(((ii+1)*K - px) * ((ii+1)*K - px) + (jj*K - py) * (jj*K - py) > 150*150){
                is_ok = false;
            }
            if((ii*K - px) * (ii*K - px) + ((jj+1)*K - py) * ((jj+1)*K - py) > 150*150){
                is_ok = false;
            }
            if(((ii+1)*K - px) * ((ii+1)*K - px) + ((jj+1)*K - py) * ((jj+1)*K - py) > 150*150){
                is_ok = false;
            }
            if(is_ok){
                ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;

    // print(ans1);

}
