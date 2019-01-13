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
    cin >> N;
    string sn = to_string(N);
    ll ans = 0;
    ll n = sn.size();
    rep(i,0,n){
        if(i == 0){
            if(sn[i] == '1'){
                string ss = sn.substr(1,n-1);
                ans += atol(ss.c_str()) + 1;
            }else{
                ans += pow(10, n-1);
            }
        }else{
            string sp = sn.substr(0,i);
            ll val = atol(sp.c_str());
            ans += pow(10,n-1-i) * val;
            if(sn[i] == '1'){
                string ss = sn.substr(i+1,n-i-1);
                ans += atol(ss.c_str()) + 1;
            }else if(sn[i] != '0'){
                ans += pow(10, n-1-i);
            }
        }
    }
    print(ans);
}