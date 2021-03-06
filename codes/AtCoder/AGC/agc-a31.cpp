#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 1;
    map<char, ll> mp;
    rep(i,0,N){
        mp[S[i]]++;
    }
    rep(i,0,26){
        if(mp['a'+i] == 0) continue;
        ans *= (mp['a'+i] + 1) % MOD;
        ans %= MOD;
    }
    print((ans-1+MOD) % MOD);


}
