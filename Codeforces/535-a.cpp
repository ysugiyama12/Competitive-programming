#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll q;
    ll r[510][4];
    cin >> q;
    rep(i,0,q){
        rep(j,0,4){
            cin >> r[i][j];
        }
    }
    rep(i,0,q){
        if(r[i][0] != r[i][3]){
            cout << r[i][0] << " " << r[i][3] << endl;
        }else{
            cout << r[i][1] << " " << r[i][2] << endl;
        }
    }
}