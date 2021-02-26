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
    string S;
    cin >> N >> S;
    bool ok = true;
    ll lv = 0, rv = 0;
    ll minus_cnt = 0;
    rep(i,0,N){
        if(S[i] == '('){
            lv++;
        }else{
            if(lv > 0){
                lv--;
            }else{
                minus_cnt++;
                lv = 0;
            }
        }
    }
    if(lv == 0 && minus_cnt == 0){
        print("Yes");
    }else if(lv == 1 && minus_cnt == 1){
        print("Yes");
    }else{
        print("No");
    }
    
}