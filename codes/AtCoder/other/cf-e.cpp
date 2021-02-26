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
    ll N;
    cin >> N;
    vector<ll> ans;
    ll n = (N+4)/5;
    rep(i,0,n){
        cout << "? ";
        rep(j,0,i*5){
            cout << "0 ";
        }
        if(i != n-1){
            rep(j,i,i+5){
                cout << pow(10,j-i) << " ";
            }
            rep(j,(i+1)*5,N){
                cout << "0" << " ";
            }
        }else{
            ll t = (N%5 == 0 ? 5 : N%5);
            rep(j,i,i+t){
                cout << pow(10, j-i) << " ";
            }
            // rep(j,i+t, N){
            //     cout << "0" << " ";
            // }
        }
        cout << endl;
        ll tt;
        cin >> tt;
        while(tt > 0){
            ll amari = tt % 10;
            if(amari == 0){
                tt -= 10;
                ans.push_back(0);
            }else if(amari == 2){
                tt -= 12;
                ans.push_back(0);
            }else if(amari == 8){
                tt -= 8;
                ans.push_back(0);
            }else if(amari == 1){
                tt -= 11;
                ans.push_back(1);
            }else{
                tt -= 9;
                ans.push_back(1);
            }
            tt /= 10;
        }
    }
    cout << "! ";
    printa(ans, N);

    
}
