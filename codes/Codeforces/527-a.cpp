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
    ll t;
    ll n[110], k[110];
    cin >> t;
    rep(i,0,t){
        cin >> n[i] >> k[i];
    }
    rep(i,0,t){
        if(n[i] % k[i] == 0){
            ll v = n[i] / k[i];
            rep(j,0,k[i]){
                rep(m,0,v){
                    char c = 'a' + j;
                    cout << c;
                }
            }
            cout << endl;
        }else{
            ll v1 = n[i] / k[i];
            ll v2 = n[i] % k[i];
            rep(j,0,k[i]){
                rep(m,0,v1){
                    char c = 'a' + j;
                    cout << c;
                }
                if(j < v2){
                    char c = 'a' + j;
                    cout << c;
                }
            }
            cout << endl;
        }
    }
}
