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
    ll S[1000010];
    ll M = (1LL<<N);
    rep(i,0,M) cin >> S[i];
    sort(S, S+M, greater<ll>());
    bool ok = true;
    ll min_cnt = 1, min_val = S[0];
    ll idx = 1;
    for(ll bit = 1; bit <= (1LL<<(N-1)); bit *= 2){
        ll max_val = S[idx];
        ll cnt = 0;
        rep(j,idx, idx+bit){
            if(S[j] == max_val){
                cnt++;
            }else{
                break;
            }
        }
        if(max_val == min_val){
            ll diff = idx - min_cnt;
            if(diff < cnt){
                print("No");
                return 0;
            }else{
                min_cnt += cnt;
            }
        }else{
            min_val = max_val;
            min_cnt = cnt;
        }
        idx += bit;
    }
    print("Yes");

}