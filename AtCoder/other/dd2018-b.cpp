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
    ll N, K, R;
    cin >> N >> K >> R;
    ll v = N - K;
    if(R > v * (v+1) / 2){
        print("No Luck");
        return 0;
    }
    vector<ll> ans;
    ll flg[100010] = {};
    ll r = R;
    rep(i,1,N-K+1){
        ll tt = N-K-i+1;
        if(r >= tt){
            r -= tt;
            flg[i] = 1;
        }
    }
    rep(i,1,N){
        if(flg[i] == 0 && i <= (N-K)){
            ans.push_back(i);
        }
    }
    rrep(i,N,1){
        if(flg[i] == 1 || i > (N-K)){
            ans.push_back(i);
        }
    }
    printa(ans,N);
}
