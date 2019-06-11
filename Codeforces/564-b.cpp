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
    rep(m,1,3000){
        ll v = m * 2 - 1;
        if(v >= N){
            print(m);
            ll idx = 0;
            ll r = 1, c = 1; 
            while(idx < N){
                if(c < m){
                    print2(r,c);
                    c++;
                }else{
                    print2(r,c);
                    r++;
                }
                idx++;
            }
            return 0;
        }
    }

    
}