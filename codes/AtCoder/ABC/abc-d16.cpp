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
    ll Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    ll N;
    ll X[110], Y[110];
    cin >> N;
    rep(i,0,N){
        cin >> X[i] >> Y[i];
    }
    X[N] = X[0];
    Y[N] = Y[0];
    ll ans = 0;
    rep(i,0,N){
        ll ta = (X[i] - X[i+1]) * (Ay - Y[i]) + (Y[i] - Y[i+1]) * (X[i] - Ax);
        ll tb = (X[i] - X[i+1]) * (By - Y[i]) + (Y[i] - Y[i+1]) * (X[i] - Bx);
        ll tc = (Ax - Bx) * (Y[i] - Ay) + (Ay - By) * (Ax - X[i]);
        ll td = (Ax - Bx) * (Y[i+1] - Ay) + (Ay - By) * (Ax - X[i+1]);
        if(tc * td < 0 && ta * tb < 0){
            ans++;
        }
    }
    print(1 + ans/2);

}
