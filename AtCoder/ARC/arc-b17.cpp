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
    ll N;
    char x[110][10];
    ll ans = 0;
    cin >> N;
    rep(i,0,N){
        rep(j,0,9){
            cin >> x[i][j];
            if(x[i][j] == 'x') ans++;
        }
    }
    rep(j,0,9){
        rep(i,0,N-1){
            if(x[i][j] == 'o' && x[i+1][j] != 'o') ans++;
        }
        if(x[N-1][j] == 'o') ans++;
    }
    print(ans);

}
