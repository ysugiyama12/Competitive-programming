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
    ll Na, Nb;
    cin >> Na >> Nb;
    ll A[100010], B[100010];
    rep(i,0,Na){
        cin >> A[i];
    }
    rep(i,0,Nb){
        cin >> B[i];
    }
    map<ll,ll> mp;
    rep(i,0,Na){
        mp[A[i]]++;
    }
    rep(i,0,Nb){
        mp[B[i]]++;
    }
    double cnt1 = 0, cnt2 = 0;
    for(auto &e: mp){
        if(e.second == 1){
            cnt1++;
        }else if(e.second == 2){
            cnt2++;
            cnt1++;
        }
    }
    double ans = cnt2/cnt1;
    cout << setprecision(10) << ans << endl;

}
