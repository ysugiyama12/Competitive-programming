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
    ll T,N,M;
    ll A[110], B[110];
    cin >> T;
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    sort(A, A+N, greater<ll>());
    cin >> M;
    rep(i,0,M){
        cin >> B[i];
    }
    sort(B, B+M, greater<ll>());
    if(N < M){
        print("no");
        return 0;
    }
    bool ok = true;
    ll idx = 0;
    rep(i,0,M){
        if(idx == N){
            ok = false;
            break;
        }
        while(A[idx] > B[i]){
            idx++;
        }
        if(idx == N){
            ok = false;
            break;
        }
        if(B[i] - A[idx] > T){
            ok = false;
            break;
        }else{
            idx++;
        }
    }
    if(ok){
        print("yes");
    }else{
        print("no");
    }
}
