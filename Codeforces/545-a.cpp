#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll t[100010];
    cin >> N;
    rep(i,0,N) cin >> t[i];
    ll sum[100010] = {};
    rep(i,0,N) sum[i+1] = sum[i] + t[i]; 
    ll cnt = 1;
    vector<ll> v;
    rep(i,1,N){
        if(t[i] != t[i-1]){
            v.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    v.push_back(cnt);
    ll ans = 0;
    rep(i,0,v.size()-1){
        ll k = min(v[i], v[i+1]);
        ans = max(ans, k*2);
    }
    print(ans);
    
}