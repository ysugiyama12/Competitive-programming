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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll cnt_A = 0;
    ll ans = 0;
    ll N = S.size();
    ll is_B = 0;
    ll idx = 1;
    if(S[0] == 'A') cnt_A++;
    while(1){
        if(idx >= N) break;
        if(S[idx] == 'A'){
            cnt_A++;
            idx++;
        }else if(idx <= N-2 && S[idx] == 'B' && S[idx + 1] == 'C'){
            if(cnt_A > 0) ans += cnt_A;
            idx += 2;
        }else{
            cnt_A = 0;
            idx++;
        }

    }
    print(ans);

    
}



























































