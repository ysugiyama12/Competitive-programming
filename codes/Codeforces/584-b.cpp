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
    ll a[110], b[110];
    rep(i,0,N) cin >> a[i] >> b[i];
    ll ans = 0;
    rep(i,0,10010){
        ll cnt = 0;
        rep(j,0,N){
            if(i < b[j]){
                if(S[j] == '1') cnt++;
            }else{
                ll v = (i - b[j]) / a[j];
                if(v % 2 == 1){
                    if(S[j] == '1') cnt++;
                }else{
                    if(S[j] == '0') cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    print(ans);

    
}