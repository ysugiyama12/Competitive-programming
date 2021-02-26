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
    string L;
    cin >> L;
    ll N = L.size();
    ll over = 0, ˜not_over = 1;
    reverse(L.begin(), L.end());
    rep(i,0,N){
        if(L[i] == '1'){
            not_over *= 3;
            not_over += over;
            not_over %= MOD;
            over *= 2;
            over %= MOD;
        }else{
            over = over * 3 + not_over * 2;
            over %= MOD;
        }
    }
    print(not_over);

    
}