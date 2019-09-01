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
    string S;
    cin >> S;
    ll ans[11] = {};
    rep(i,0,N){
        if(S[i] == 'L'){
            rep(j,0,10){
                if(ans[j] == 0){
                    ans[j]++;
                    break;
                }
            }
        }else if(S[i] == 'R'){
            rrep(j,9,0){
                if(ans[j] == 0){
                    ans[j]++;
                    break;
                }
            }
        }else{
            ll num = S[i] - '0';
            ans[num]--;
        }
    }
    rep(i,0,10) cout << ans[i];
    cout << endl;
    
}