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
    ll N,K;
    cin >> N >> K;
    ll T[10][10];
    rep(i,0,N){
        rep(j,0,K){
            cin >> T[i][j];
        }
    }
    bool ans = true;
    rep(i,0,pow(K,N)){
        ll val[10] = {};
        ll num = i;
        ll idx = 0;
        while(num > 0){
            val[idx] = num % K;
            idx++;
            num /= K;
        }
        ll v = T[0][val[0]];
        rep(j,1,N){
            v ^= T[j][val[j]];
        }
        if(v == 0){
            ans = false;
        }
    }
    if(!ans){
        print("Found");
    }else{
        print("Nothing");
    }

}
