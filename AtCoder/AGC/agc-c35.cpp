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
    if(N % 2 == 0 || N == 1){
        print("No");
        return 0;
    }
    vector<lpair> ans;
    ans.push_back(make_pair(1,2));
    ans.push_back(make_pair(2,3));
    ans.push_back(make_pair(3,N+1));
    ans.push_back(make_pair(1,N+3));
    ans.push_back(make_pair(N+3,N+2));
    if(N >= 5){
        for(int i = 5; i <= N; i += 2){
            ans.push_back(make_pair(1, N+i));
            ans.push_back(make_pair(N+i, N+i-1));
            ans.push_back(make_pair(1, i-1));
            ans.push_back(make_pair(i-1, i));
        }
    }
    print("Yes");
    if(1^2 == 3){
        print("ok");
    }
    rep(i,0,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    

    // 1 2 3 1 2 3


    
}