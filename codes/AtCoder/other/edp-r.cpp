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
ll N,K;
ll a[55][55];
ll ans[55][55] = {};
ll tmp[55][55] = {};
void multiple1(){
    rep(i,0,N){
        rep(j,0,N){
            tmp[i][j] = 0;
        }
    }

    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,N){
                tmp[i][j] += a[i][k] * ans[k][j] % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            ans[i][j] = tmp[i][j];
        }
    }
}
void multiple2(){
    rep(i,0,N){
        rep(j,0,N){
            tmp[i][j] = 0;
        }
    }

    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,N){
                tmp[i][j] += a[i][k] * a[k][j] % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            a[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i,0,N){
        rep(j,0,N){
            cin >> a[i][j];
        }
    }
    rep(i,0,N){
        ans[i][i] = 1;
    }

    rep(i,0,61){
        if((K>>i) & 1){
            multiple1();
        }
        multiple2();
    }
    ll cnt = 0;
    rep(i,0,N){
        rep(j,0,N){
            cnt += ans[i][j] % MOD;
            cnt %= MOD;
        }
    }
    print(cnt);

}
