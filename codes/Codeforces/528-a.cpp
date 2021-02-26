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
    string s;
    cin >> s;
    ll N = s.size();
    char ans[100];
    if(N % 2 == 0){
        ll nn = N/2;
        rep(i,0,nn){
            ans[2*i] = s[N-1-i];
        }
        rep(i,0,nn){
            ans[2*i+1] = s[i];
        }
    }else{
        ll nn = (N+1)/2;
        rep(i,0,nn){
            ans[2*i] = s[i];
        }
        rep(i,0,nn-1){
            ans[2*i+1] = s[N-1-i];
        }

    }
    rep(i,0,N){
        cout << ans[N-1-i];
    }
    cout << endl;
}
