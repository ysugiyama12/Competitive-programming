#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
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
    ll MOD = 1e9 + 7;
    rep(i,0,N){
        cin >> A[i];
    }
    sort(A, A+N);
    ll ans = 1;
    bool is_ok = true;
    rep(i,0,N){
        if(N % 2 != 0){
            if(A[0] != 0){
                is_ok = false;
            }else{
                if(A[i] != 2 *  ((i+1)/2)){
                    is_ok = false;
                }
            }
        }else{
            if(A[i] != 2 * (i/2) + 1){
                is_ok = false;
            }

        }
    }
    if(!is_ok){
        print(0);
        return 0;
    }else{
        if(N % 2 != 0){
            rep(i,0,(N-1)/2){
                ans *= 2;
                ans %= MOD;
            }
        }else{
            rep(i,0,N/2){
                ans *= 2;
                ans %= MOD;
            }
        }
        print(ans);
    }
}
