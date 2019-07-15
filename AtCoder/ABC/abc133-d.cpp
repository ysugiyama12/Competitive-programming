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
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll val = 0;
    rep(i,0,N){
        if(i % 2 == 0){
            val += 2 * A[i];
        }else{
            val -= 2 * A[i];
        }
    }
    ll x = val / 2;
    ll tt = 0;
    vector<ll> ans;
    rep(i,0,N){
        if(i % 2 == 0){
            tt = A[i]*2 - tt;
            ans.push_back(tt-x);
        }else{
            tt = A[i]*2 - tt;
            ans.push_back(tt+x);
        }
    }
    cout << ans[N-1] << " ";
    rep(i,0,N-1){
        cout << ans[i] << " \n"[i == N-2];
    }



    
}