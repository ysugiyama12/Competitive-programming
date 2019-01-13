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
    ll x1, y1, r;
    ll x2, y2, x3, y3;
    cin >> x1 >> y1 >> r;
    cin >> x2 >> y2 >> x3 >> y3;
    if(x3 >= x1+r && y3 >= y1+r && x2 <= x1-r && y2 <= y1-r){
        print("NO");
        print("YES");
    }else if((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1) <= r*r && (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) <= r*r && (x2-x1)*(x2-x1) + (y3-y1)*(y3-y1) <= r*r && (x3-x1)*(x3-x1) + (y2-y1)*(y2-y1) <= r*r){
        print("YES");
        print("NO");
    }else{
        print("YES");
        print("YES");
    }
}
