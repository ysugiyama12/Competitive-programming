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
    ll n;
    string s[210];
    cin >> n;
    rep(i,0,2*n-2){
        cin >> s[i];
    }
    vector<string> ss[110];
    rep(i,0,2*n-2){
        ll sz = s[i].size();
        ss[sz].push_back(s[i]);
    }
    rep(i,0,2){
        rep(j,0,2){
            string s1 = ss[n-1][i] + ss[1][j];
            // print(s1);
            bool flg = true;
            rep(k,1,n){
                string v1 = ss[k][0];
                string v2 = ss[k][1];
                // print(v1);
                // print(v2);
                // print("--");
                // print(s1.substr(0,k) == v1);
                if(s1.substr(0,k) == v1 && s1.substr(n-k,k) == v2){
                }else if(s1.substr(0,k) == v2 && s1.substr(n-k,k) == v1){
                }else{
                    // print(s1);
                    // print(v1);
                    // print(v2);
                    // print(s1.substr(0,k) == v1);
                    // print(s1.substr(n-k-1,k) == v2);
                    // print(s1.substr(n-k-1,k));
                    // print("--");
                    flg = false;
                }
            }
            ll check[110] = {};
            if(flg){
                rep(k,0,2*n-2){
                    ll len = s[k].size();
                    if(s1.substr(0,len) == s[k] && check[len] == 0){
                        cout << 'P';
                        check[len] = 1;
                    }else{
                        cout << 'S';
                    }
                }
                cout << endl;
                return 0;

            }
        }
    }

}
