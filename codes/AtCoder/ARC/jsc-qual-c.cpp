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
    ll cnt = 0;
    ll lr[200010] = {};
    rep(i,0,2*N){
        if(S[i] == 'B'){
            if(cnt % 2 == 0){
                lr[i] = 1;
                cnt = 1;
            }else{
                cnt = 0;
            }
        }else{
            if(cnt % 2 == 1){
                lr[i] = 1;
                cnt = 0;
            }else{
                cnt = 1;
            }
        }
    }
    ll ans = 1;
    rep(i,0,N){
        ans *= (i+1);
        ans %= MOD;
    }
    ll l_cnt = 0;
    rep(i,0,2*N) l_cnt += lr[i];
    if(l_cnt != N){
        print(0);
        return 0;
    }
    ll tt = 0;
    rep(i,0,2*N){
        if(lr[i] == 1){
            tt++;
        }else{
            ans *= tt;
            ans %= MOD;
            tt--;
        }
        if(tt < 0){
            print(0);
            return 0;
        }
    }
    print(ans);
    



    
}