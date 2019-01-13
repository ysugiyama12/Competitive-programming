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
int x[6][6];
bool check(vector<int> v){
    int y[6][6];
    int idx = 0;
    rep(i,0,5){
        rep(j,0,5){
            if(x[i][j] == 0){
                y[i][j] = v[idx];
                idx++;
            }else{
                y[i][j] = x[i][j];
            }
        }
    }
    bool flg = true;
    rep(i,0,5){
        rep(j,0,3){
            if((y[i][j] - y[i][j+1]) * (y[i][j+1] - y[i][j+2]) > 0){
                flg = false;
            }
        }
    }
    rep(i,0,3){
        rep(j,0,5){
            if((y[i][j] - y[i+1][j]) * (y[i+1][j] - y[i+2][j]) > 0){
                flg = false;
            }
        }
    }
    return flg;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int is_num[26] = {};
    rep(i,0,5){
        rep(j,0,5){
            cin >> x[i][j];
            is_num[x[i][j]] = 1;
        }
    }
    vector<int> num_arr;
    rep(i,1,26){
        if(is_num[i] == 0){
            num_arr.push_back(i);
        }
    }
    if(num_arr.size() > 8) return 0;
    ll ans = 0;
    do{
        if(check(num_arr)) ans++;
    }while(next_permutation(num_arr.begin(), num_arr.end()));
    print(ans);
}
