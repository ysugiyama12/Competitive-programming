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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M,K;
    cin >> M >> K;
    if(M == 1 && K == 1){
        print("-1");
        return 0;
    }
    ll n = (1LL<<M);
    if(M == 0 && K == 0){
        print("0 0");
        return 0;
    }
    if(M == 0 && K == 1){
        print("-1");
        return 0;
    }
    if(K >= n){
        print("-1");
        return 0;
    }
    if(M == 1 && K == 0){
        print("0 0 1 1");
    }
    vector<ll> ans;
    rep(i,0,n){
        if(i != K){
            // cout << i << " ";
            ans.push_back(i);
        }
    }
    ans.push_back(K);
    rrep(i,n-1,0){
        if(i != K) ans.push_back(i);
    }
    ans.push_back(K);
    rep(i,0,2*n){
        cout << ans[i] << " \n"[i == 2*n-1];
    }

    
}