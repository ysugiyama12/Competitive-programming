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
inline bool isPrime(ll x){ //素数かどうか判定
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(ll i=3;i<=sqrt(x)+1;i+=2) if(x%i==0) return false;
    return true;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[200010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    ll cnt1 = 0;
    rep(i,0,N){
        if(A[i] == 1) cnt1++;
    }
    ll cnt2 = N - cnt1;
    ll v = 0;
    vector<ll> ans;
    rep(i,0,N){
        if(cnt1 == 0){
            ans.push_back(2);
            cnt2--;
            v += 2;
        }else if(cnt2 == 0){
            ans.push_back(1);
            cnt1--;
            v++;
        }else{
            if(isPrime(v+1)){
                ans.push_back(1);
                cnt1--;
                v++;
            }else{
                ans.push_back(2);
                cnt2--;
                v += 2;
            }

        }

    }
    rep(i,0,N){
        cout << ans[i] << " \n"[i == N-1];
    }

    
}