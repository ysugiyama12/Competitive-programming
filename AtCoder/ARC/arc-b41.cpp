#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll N,M;
ll b[510][510];
ll a[510][510] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,N){
        string S;
        cin >> S;
        rep(j,0,M){
            b[i][j] = S[j] - '0';
        }
    }
    rep(i,1,N-1){
        rep(j,1,M-1){
            if(b[i+1][j] != 0 && b[i-1][j] != 0 && b[i][j+1] != 0 && b[i][j-1] != 0){
                ll val = min(min(b[i+1][j], b[i-1][j]), min(b[i][j+1], b[i][j-1]));
                a[i][j] = val;
                b[i+1][j] -= val; b[i-1][j] -= val; b[i][j+1] -= val; b[i][j-1] -= val;
            }
        }
    }
    rep(i,0,N){
        rep(j,0,M){
            cout << a[i][j];
        }
        cout << endl;
    }
}
