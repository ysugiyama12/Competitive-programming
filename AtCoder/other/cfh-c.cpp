#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    ll ans = 0;
    map<ll,ll> mp;
    ll v = 0;
    mp[0] = 1;
    rep(i,0,N){
        if(S[i] == '('){
            v++;
            mp[v] = 1;
        }else{
            v--;
            ans += mp[v];
            mp[v]++;
        }
    }
    print(ans);
}
