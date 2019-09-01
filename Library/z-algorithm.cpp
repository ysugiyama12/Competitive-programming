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

vector< ll > z_algorithm(const string &s) {
    vector< ll > prefix(s.size());
    for(ll i = 1, j = 0; i < s.size(); i++) {
        if(i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        }else{
            ll k = max(0LL, j + prefix[j] - i);
            while(i + k < s.size() && s[k] == s[i + k]) ++k;
            prefix[i] = k;
            j = i;
        }
    }
  prefix[0] = (ll) s.size();
  return prefix;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string T, P;
    cin >> T >> P;
    string S = P + '$' + T;
    vector<ll> res = z_algorithm(S);
    // printa(res, res.size());
    ll nt = T.size(), np = P.size();
    rep(i, np + 1, np + nt + 1){
        if(res[i] == np) print(i - (np+1));
    }
}