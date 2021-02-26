#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
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
    ll N,T;
    ll t[200010];
    cin >> N >> T;
    rep(i,0,N){
        cin >> t[i];
    }
    ll ans = 0;
    ll tt = T;
    rep(i,1,N){
        if(tt > t[i] - t[i-1]){
            tt -= (t[i] - t[i-1]);
            ans += t[i] - t[i-1];
            tt = T;
        }else{
            tt = T;
            ans += tt;
        }

    }
    ans += tt;
    print(ans);


}