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
    string A;
    cin >> A;
    ll ans = 0;
    ll N = A.size();
    ll diff_cnt = 0;
    rep(i,0,N/2){
        if(A[i] != A[N-1-i]) diff_cnt++;
    }
    rep(i,0,N/2){
        if(A[i] == A[N-1-i]){
            ans += 25;
        }else{
            if(diff_cnt == 1){
                ans += 24;
            }else{
                ans += 25; 
            }
        }
    }
    ans *= 2;
    if(N % 2 == 1){
        string Av = A;
        reverse(Av.begin(), Av.end());
        if(A != Av){
            ans += 25;
        }
    }
    print(ans);

}
