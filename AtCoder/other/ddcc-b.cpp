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
    int N;
    cin >> N;
    int ans = 0;
    rep(i,0,N){
        rep(j,0,N){
            bool flg = true;
            int px = i;
            int py = j;
            if(abs(2*px-N) + abs(2*py-N) > N){
                flg = false;
            }
            px++;
            if(abs(2*px-N) + abs(2*py-N) > N){
                flg = false;
            }
            px--;
            py++;
            if(abs(2*px-N) + abs(2*py-N) > N){
                flg = false;
            }
            px++;
            if(abs(2*px-N) + abs(2*py-N) > N){
                flg = false;
            }
            if(flg) ans++;

        }
    }
    print(ans);

}
