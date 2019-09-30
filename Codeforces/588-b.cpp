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
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll num = 0;
    string ans = "";
    rep(i,0,N){
        if(num >= K){
            ans += S[i];
        }else{
            if(i == 0 && S.size() != 1){
                if(S[i] != '1'){
                    num++;
                    ans += '1';
                }else{
                    ans += '1';
                }
            }else{
                if(S[i] != '0'){
                    num++;
                    ans += '0';
                }else{
                    ans += '0';
                }
            }
        }
    }
    print(ans);

    
}