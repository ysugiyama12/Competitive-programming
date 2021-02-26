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
ll dpA[20][2][2];
ll dpB[20][2][2];
string A,B;
ll recA(ll k = 0, bool tight = true, bool ok = false){
    if(k == A.size()){
        return ok;
    }
    ll x = A[k] - '0';
    ll r = (tight) ? x : 9;
    if(dpA[k][tight][ok] != -1) return dpA[k][tight][ok];
    ll res = 0;
    rep(i,0,r+1){
        res += recA(k+1, tight && i == r, ok || (i == 4 || i == 9));
    }
    dpA[k][tight][ok] = res;
    return res;
}

ll recB(ll k = 0, bool tight = true, bool ok = false){
    if(k == B.size()){
        return ok;
    }
    ll x = B[k] - '0';
    ll r = (tight) ? x : 9;
    if(dpB[k][tight][ok] != -1) return dpB[k][tight][ok];
    ll res = 0;
    rep(i,0,r+1){
        res += recB(k+1, tight && i == r, ok || (i == 4 || i == 9));
    }
    dpB[k][tight][ok] = res;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;
    a--;
    A = to_string(a); B = to_string(b);
    memset(dpA, -1, sizeof(dpA));
    memset(dpB, -1, sizeof(dpB));
    print(recB() - recA());

    
}
