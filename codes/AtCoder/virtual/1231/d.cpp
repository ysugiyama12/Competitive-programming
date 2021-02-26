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
    ll N;
    ll p[20010];
    cin >> N;
    rep(i,0,N){
        cin >> p[i];
        p[i]--;
    }
    ll a[20010], b[20010];
    rep(i,0,N){
        a[i] = (i+1) * 30000;
        b[N-1-i] = (i+1) * 30000;
    }
    rep(i,0,N){
        a[p[i]] += i;
    }
    rep(i,0,N){
        if(i != N-1){
            cout << a[i] << " ";
        }else{
            cout << a[i] << endl;
        }
    }
    rep(i,0,N){
        if(i != N-1){
            cout << b[i] << " ";
        }else{
            cout << b[i] << endl;
        }
    }

}
