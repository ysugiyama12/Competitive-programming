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
    ll a[30];
    rep(i,2,31){
        cin >> a[i];
    }
    
    // double n = 1;
    // rep(i,1,31){
    //     n *= i;
    // }
    // print(n);
    // ll v2 = a[2];
    // int v[45] = {};
    // rep(i,0,41){
    //     if(i < v2){
    //         v[i]++;
    //     }
    // }
    // sort(v, v+41);
    // do{
    //     printa(v,41);
    // }while(next_permutation(v, v+41));

}
