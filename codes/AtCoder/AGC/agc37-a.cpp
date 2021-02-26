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
    string S;
    cin >> S;
    string t = "";
    // string t2 = "";
    // S += '$';
    ll N = S.size();
    // print(N);
    ll ans = 0;
    string now = "";
    rep(i,0,N){
        string s = S.substr(i,1);
        now += s;
        // print(now);
        if(now == t){
            // now += s;
        }else{
            t = now;
            now = "";
            ans++;
            // print(i);
        }
        // print2(i,t);
    }
    // if(t.size() != 1) ans++;
    print(ans);

    
}