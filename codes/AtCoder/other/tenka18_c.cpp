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
    ll A[100010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    sort(A, A+N, greater<ll>());
    ll ans = 0;
    if(N % 2 == 0){
        rep(i,0,N/2 - 1){
            ans += 2 * A[i];
        }
        ans += A[N/2 - 1];
        ans -= A[N/2];
        rep(i,N/2 + 1, N){
            ans -= 2 * A[i];
        }
    }else{
        ll ans_1 = 0, ans_2 = 0;
        rep(i,0,(N+1)/2 - 2){
            ans_1 += 2 * A[i];
        }
        ans_1 += A[(N+1)/2 - 2] + A[(N+1)/2 - 1];
        rep(i,(N+1)/2,N){
            ans_1 -= 2 * A[i];
        }
        sort(A, A+N);
        rep(i,0,(N+1)/2 - 2){
            ans_2 -= 2 * A[i];
        }
        ans_2 -= (A[(N+1)/2 - 2] + A[(N+1)/2 - 1]);
        rep(i,(N+1)/2,N){
            ans_2 += 2 * A[i];
        }
        ans = max(ans_1, ans_2);

    }
    print(ans);
}
