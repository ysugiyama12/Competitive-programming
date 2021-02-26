/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    ll val = 1;
    rep(i,0,N){
        if(val == 1){
            ans += A[i]-1;
            val++;
        }else{
            if(A[i] == val){
                val++;
            }else if(A[i] < val){
                continue;
            }else{
                if(A[i] % val == 0){
                    ans += (A[i]-1) / val;
                }else{
                    ans += A[i] / val;
                }
            }

        }
    }
    print(ans);
}