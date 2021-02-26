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
    ll ans = 0;
    if(A[0] % 2 == 0){
        ans += A[0]/2;
        A[0] = 0;
    }else{
        ans += (A[0]-1)/2;
        A[0] = 1;
    }
    // print("--");
    // print(ans);
    rep(i,1,N){
        if(A[i-1] == 0){
            if(A[i] % 2 == 0){
                ans += A[i]/2;
                A[i] = 0;
            }else{
                ans += (A[i]-1)/2;
                A[i] = 1;
            }
        }else{
            if(A[i] % 2 == 0){
                ans += A[i]/2;
                if(A[i] == 0){
                    A[i] = 0;
                }else{
                    A[i] = 1;
                }
            }else{
                ans += (A[i] +1)/2;
                A[i] = 0;
            }
        }
        // print(ans);
        // printa(A,N);
    }
    print(ans);


}
