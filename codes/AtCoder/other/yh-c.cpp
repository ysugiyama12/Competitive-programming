#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K,A,B;
    cin >> K >> A >> B;
    if(A+1 >= B){
        print(1+K);
        return 0;
    }
    if(K <= A-1){
        print(1+K);
        return 0;
    }
    K -= (A-1);
    if(K % 2 == 0){
        ll ans = A + (B - A) * K/2;
        print(ans);
    }else{
        ll ans = A + (B - A) * (K/2) + 1;
        print(ans);
    }

}
