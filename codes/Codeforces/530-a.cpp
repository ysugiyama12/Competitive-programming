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
    ll w,h;
    ll u1, d1, u2, d2;
    cin >> w >> h;
    cin >> u1 >> d1 >> u2 >> d2;
    // ll val = w + h * (h+1) / 2;
    // val -= (u1+u2);
    // if(val < 0){
    //     print(0);
    // }else{
    //     print(val);
    // }
    ll weigh = w;
    rrep(i,h,0){
        weigh += i;
        if(d1 == i){
            weigh -= u1;
        }
        if(d2 == i){
            weigh -= u2;
        }
        if(weigh < 0){
            weigh = 0;
        }
    }
    if(weigh < 0){
        print(0);
    }else{
        print(weigh);
    }
}
