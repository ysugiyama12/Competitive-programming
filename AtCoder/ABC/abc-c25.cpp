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
ll b[3][3], c[3][3];
ll rec(ll pos, vector<ll> v){
    // printa(v,9);
    bool end = true;
    ll val = 0;
    rep(i,0,9){
        if(v[i] == 0) end = false;
    }
    if(end){
        // printa(v,9);
        if(v[0] == v[3]) val += b[0][0]; else val -= b[0][0];
        if(v[1] == v[4]) val += b[0][1]; else val -= b[0][1];
        if(v[2] == v[5]) val += b[0][2]; else val -= b[0][2];
        if(v[3] == v[6]) val += b[1][0]; else val -= b[1][0];
        if(v[4] == v[7]) val += b[1][1]; else val -= b[1][1];
        if(v[5] == v[8]) val += b[1][2]; else val -= b[1][2];

        if(v[0] == v[1]) val += c[0][0]; else val -= c[0][0];
        if(v[1] == v[2]) val += c[0][1]; else val -= c[0][1];
        if(v[3] == v[4]) val += c[1][0]; else val -= c[1][0];
        if(v[4] == v[5]) val += c[1][1]; else val -= c[1][1];
        if(v[6] == v[7]) val += c[2][0]; else val -= c[2][0];
        if(v[7] == v[8]) val += c[2][1]; else val -= c[2][1];
        // print(val);
        return val;
    }
    if(pos % 2 == 0){ //高橋くん, 最大化
        val = -INF;
        rep(i,0,9){
            if(v[i] == 0){
                v[i] = 1;
                val = max(val, rec(pos+1, v));
                v[i] = 0;
            }
        }
    }else{ //直子さん, 最小化
        val = INF;
        rep(i,0,9){
            if(v[i] == 0){
                v[i] = 2;
                val = min(val, rec(pos+1, v));
                v[i] = 0;
            }
        }
    }
    return val;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll sum = 0;
    rep(i,0,2){
        rep(j,0,3){
            cin >> b[i][j];
            sum += b[i][j];
        }
    }
    rep(i,0,3){
        rep(j,0,2){
            cin >> c[i][j];
            sum += c[i][j];
        }
    }
    // print(sum);
    vector<ll> v(9);
    rep(i,0,9){
        v[i] = 0;
    }
    ll ans = rec(0,v);
    print((sum + ans)/2);
    print((sum - ans)/2);
    
}

