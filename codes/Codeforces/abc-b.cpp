#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll s;
    cin >> s;
    map<ll,ll> mp;
    mp[s] = 1;
    ll v = s;
    rep(i,0,100010){
        if(v % 2 == 0){
            v = v/2;
        }else{
            v = 3 * v + 1;
        }
        if(mp[v] == 1){
            print(i+2);
            return 0;
        }
        mp[v] = 1;
    }
}
