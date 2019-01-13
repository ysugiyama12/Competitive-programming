#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    ll cnt = __builtin_popcount(n);
    // print(cnt);
    if(k < cnt || k > n){
        print("NO");
        return 0;
    }
    print("YES");
    map<ll,ll> mp;
    rep(i,0,31){
        if((n >> i) & 1){
            mp[pow(2,i)] = 1;
        }
    }
    ll v = k - cnt;
    // print(v);
    rep(i,0,v){
        for(ll j = (1LL<<30); j >= 1; j /= 2){
            if(mp[j] >= 1){
                mp[j/2] += 2;
                mp[j]--;
                break;
            }
        }
    }
    for(ll j = 1; j < (1LL<<30); j *= 2){
        rep(m,0,mp[j]){
            cout << j << " ";
        }
    }
    cout << endl;



}
