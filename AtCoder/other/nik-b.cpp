#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,K;
    cin >> N >> M >> K;
    ll A[100010], B[100010];
    rep(i,0,N) cin >> A[i];
    rep(i,0,M) cin >> B[i];
    if(N > M){
        print("Y");
    }else if(N < M){
        print("X");
    }else{
        rep(i,0,N){
            if(A[i] > B[i]){
                print("Y");
                return 0;
            }else if(A[i] < B[i]){
                print("X");
                return 0;
            }
        }
        print("Same");
    }
}
