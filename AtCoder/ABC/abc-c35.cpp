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
    ll N, Q;
    ll l[200010], r[200010];
    cin >> N >> Q;
    rep(i,0,Q){
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    ll imos[200010] = {};
    rep(i,0,Q){
        imos[l[i]]++;
        imos[r[i]+1]--;
    }
    rep(i,0,N-1){
        imos[i+1] += imos[i];
    }
    rep(i,0,N){
        if(imos[i] % 2 == 0){
            cout << '0';
        }else{
            cout << '1';
        }
    }
    cout << endl;
}
