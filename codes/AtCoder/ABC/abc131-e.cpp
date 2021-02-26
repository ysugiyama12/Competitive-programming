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
    ll N,K;
    cin >> N >> K;
    if(K > (N-1) * (N-2) / 2){
        print(-1);
        return 0;
    }
    vector<lpair> ans;
    rep(i,0,N-1){
        ans.push_back(make_pair(1, i+2));
    }
    ll v = (N-1) * (N-2) / 2 - K;
    ll cnt = 0;
    bool flg = true;
    rep(stride, 1, N-1){
        rep(num,0,N-2-stride + 1){
            if(cnt >= v){
                flg = false;
                break;
            }
            ans.push_back(make_pair(num+2, num+2+stride));
            cnt++;
        }
        if(not flg) break;
    }
    print(ans.size());
    rep(i,0,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }


}