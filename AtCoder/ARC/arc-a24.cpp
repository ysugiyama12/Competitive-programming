#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll l1,r1;
    ll L[110], R[110];
    cin >> l1 >> r1;
    map<ll,ll> mp1, mp2;
    rep(i,0,l1){
        cin >> L[i];
        mp1[L[i]]++;
    }
    rep(i,0,r1){
        cin >> R[i];
        mp2[R[i]]++;
    }
    ll ans = 0;
    for(auto &e: mp1){
        ans += min(e.second, mp2[e.first]);
    }
    print(ans);
}
