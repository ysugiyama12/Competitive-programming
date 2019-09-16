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
bool comp(lpair l1, lpair l2){
    if(l1.first - l1.second == l2.first - l2.second){
        return l1.first > l2.first;
    }
    return l1.first - l1.second > l2.first - l2.second;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        ll N,X;
        cin >> N >> X;
        ll d[110], h[110];
        rep(i,0,N) cin >> d[i] >> h[i];
        ll max_d = 0;
        rep(i,0,N) max_d = max(max_d, d[i]);
        vector<lpair> lp;
        rep(i,0,N) lp.push_back(make_pair(d[i], h[i]));
        sort(lp.begin(), lp.end(), comp);
        ll v = lp[0].first - lp[0].second;
        if(v <= 0){
            if(max_d >= X){
                print(1);
            }else{
                print(-1);
            }
        }else{
            if(max_d >= X){
                print(1);
            }else{
                X -= max_d;
                print(1 + (X+v-1) / v);
            }
        }
    }
    
}