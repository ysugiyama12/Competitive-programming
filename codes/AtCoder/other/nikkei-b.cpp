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
    string A,B,C;
    cin >> N >> A >> B >> C;
    ll ans = 0;
    rep(i,0,N){
        if(A[i] == B[i] && B[i] == C[i]){
        }else if(A[i] == B[i] && B[i] != C[i]){
            ans++;
        }else if(B[i] == C[i] && A[i] != B[i]){
            ans++;
        }else if(A[i] == C[i] && A[i] != B[i]){
            ans++;
        }else{
            ans += 2;
        }
    }
    print(ans);
}
