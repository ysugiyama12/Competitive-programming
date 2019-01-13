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
    ll N;
    ll T[1010], A[1010];
    cin >> N;
    rep(i,0,N){
        cin >> T[i] >> A[i];
    }
    ll t = T[0], a = A[0];
    rep(i,1,N){
        if(t <= T[i] && a <= A[i]){
            t = T[i];
            a = A[i];
        }else if(t > T[i] && a <= A[i]){
            ll num = (t - 1) / T[i];
            t = (num + 1) * T[i];
            a = (num + 1) * A[i];
        }else if(t <= T[i] && a > A[i]){
            ll num = (a - 1) / A[i];
            t = (num + 1) * T[i];
            a = (num + 1) * A[i];
        }else{
            ll num1 = (t - 1) / T[i];
            ll num2 = (a - 1) / A[i];
            ll num = max(num1, num2);
            t = (num + 1) * T[i];
            a = (num + 1) * A[i];
        }
    }
    print(t + a);
}
