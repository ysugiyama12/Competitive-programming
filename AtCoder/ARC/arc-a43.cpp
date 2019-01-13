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
    double A,B;
    double S[100010];
    cin >> N >> A >> B;
    rep(i,0,N){
        cin >> S[i];
    }
    sort(S,S+N);
    double ave = 0;
    rep(i,0,N){
        ave += S[i];
    }
    ave /= N;//P*ave + Q = A
    // P*(S[0] - S[N-1]) = B
    double diff = S[N-1] - S[0];
    if(diff == 0){
        print(-1);
        return 0;
    }
    double P = B / diff;
    double Q = A - P * ave;
    cout << setprecision(10) << P << " " << Q << endl;



}
