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
    string S;
    cin >> S;
    ll N = S.size();
    ll cnt = 0;
    rep(i,0,N){
        if(S[i] == '2') cnt++;
    }
    if(N % 2 == 1 || cnt != N/2){
        print(-1);
        return 0;
    }
    ll n_two = 0, n_five = 0;
    ll ans = 0;
    bool ok = true;
    rep(i,0,N){
        if(S[i] == '2'){
            if(n_five > 0){
                n_five--;
                n_two++;
            }else{
                ans++;
                n_two++;
            }
        }else{
            if(n_two > 0){
                n_two--;
                n_five++;
            }else{
                ok = false;
            }
        }
    }
    if(!ok){
        print(-1);
    }else{
        print(ans);
    }

    
}