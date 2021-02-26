#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string pos[100010] = {};
    ll lv = 0, rv = N-1;
    cout << 0 << endl;
    cin >> pos[0];
    if(pos[0] == "Vacant") return 0;
    cout << N-1 << endl;
    cin >> pos[N-1];
    if(pos[N-1] == "Vacant") return 0;
    while(rv - lv > 1){
        ll mid = (lv + rv) / 2;
        cout << mid << endl;
        cin >> pos[mid];
        if(pos[mid] == "Vacant") return 0;
        if(pos[mid] == pos[lv]){
            if((mid - lv - 1) % 2 == 0){
                rv = mid;
            }else{
                lv = mid;
            }
        }else{
            if((mid - lv - 1) % 2 == 0){
                lv = mid;
            }else{
                rv = mid;
            }
        }
    }

}
