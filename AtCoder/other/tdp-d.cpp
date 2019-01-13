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
inline vector<ll> factor(ll M){ //素因数分解
    vector<ll> dd;
    if(M == 1){
        dd.push_back(1);
        return dd;
    }
    for(ll i = 2; i*i <= M; i++){
        while(M % i == 0){
            dd.push_back(i);
            M /= i;
        }
    }
    if(M != 1) dd.push_back(M);
    sort(dd.begin(), dd.end());
    return dd;
}
double dp[110][40][40][40];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,D;
    cin >> N >> D;
    map<ll, double> mp[110];
    vector<ll> dd = factor(D);
    // printa(dd, dd.size());
    ll dn = dd.size();
    int c2 = 0, c3 = 0, c5 = 0;
    bool is_impossible = false;
    rep(i,0,dn){
        if(dd[i] == 2) c2++;
        else if(dd[i] == 3) c3++;
        else if(dd[i] == 5) c5++;
        else if(dd[i] != 1) is_impossible = true;
    }
    if(is_impossible){
        print(0);
        return 0;
    }
    dp[0][0][0][0] = 1.0;
    rep(i,1,N+1){
        rep(a,0,c2+1){
            rep(b,0,c3+1){
                rep(c,0,c5+1){
                    dp[i][a][b][c] += (dp[i-1][a][b][c] / 6);
                    dp[i][min(a+1,c2)][b][c] += (dp[i-1][a][b][c] / 6);
                    dp[i][a][min(b+1,c3)][c] += (dp[i-1][a][b][c] / 6);
                    dp[i][min(a+2,c2)][b][c] += (dp[i-1][a][b][c] / 6);
                    dp[i][a][b][min(c+1,c5)] += (dp[i-1][a][b][c] / 6);
                    dp[i][min(a+1,c2)][min(c3,b+1)][c] += (dp[i-1][a][b][c] / 6);
                }
            }
        }
    }
    cout << setprecision(10) << dp[N][c2][c3][c5] << endl;



}
