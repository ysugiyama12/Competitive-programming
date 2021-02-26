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
    ll L;
    ll B[100010];
    cin >> L;
    rep(i,0,L){
        cin >> B[i];
    }
    ll A[100010] = {};
    A[0] = 0;
    rep(i,0,L-1){
        rep(bit,0,33){
            if(!((A[i]>>bit) & 1) && ((B[i]>>bit) & 1)){
                A[i+1] += (1LL<<bit);
            }else if(((A[i]>>bit) & 1) && !((B[i]>>bit) & 1)){
                A[i+1] += (1LL<<bit);
            }
        }
    }
    if((A[0]^A[L-1]) != B[L-1]){
        print(-1);
    }else{
        rep(i,0,L){
            print(A[i]);
        }
    }
}
