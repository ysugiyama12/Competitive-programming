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
    ll N;
    cin >> N;
    ll v;
    vector<lpair> ans;
    if(N % 2 == 0){
        v = N+1;
    }else{
        v = N;
    }
    rep(i,1,N+1){
        rep(j,1,N+1){
            if(i >= j) continue;
            if(i + j != v){
                ans.push_back(make_pair(i,j));
            }
        }
    }
    print(ans.size());
    rep(i,0,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    
}