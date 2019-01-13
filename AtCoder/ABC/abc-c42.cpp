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
    int N,K;
    int D[11];
    cin >> N >> K;
    map<int,int> mp;
    rep(i,0,K){
        cin >> D[i];
        mp[D[i]] = 1;
    }
    rep(i,N,100000){
        string str = to_string(i);
        bool flg = true;
        rep(j,0,str.size()){
            if(mp[str[j] - '0'] == 1){
                flg = false;
            }
        }
        if(flg){
            print(i);
            return 0;
        }
    }
}

