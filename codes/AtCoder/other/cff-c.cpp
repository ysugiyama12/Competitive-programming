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
    ll D[55];
    cin >> N;
    rep(i,0,N) cin >> D[i];
    sort(D, D+N);
    ll lv = 0, rv = 0;
    ll pos[25] = {};
    pos[0] = 1;
    rep(i,0,N){
        if(D[i] - lv > D[i] - rv){
            pos[24-D[i]]++;
            lv = D[i];
        }else{
            pos[D[i]]++;
            rv = D[i];
        }
    }
    rep(i,0,24){
        if(pos[i] >= 2){
            print(0);
            return 0;
        }
    }
    vector<ll> tt;
    rep(i,0,24){
        if(pos[i] == 1){
            tt.push_back(i);
        }
    }
    ll ans = INF;
    ll n = tt.size();
    rep(i,0,n){
        ans = min(ans, abs(tt[(i+1)%n] - tt[i]));
    }
    print(ans);


    
}
