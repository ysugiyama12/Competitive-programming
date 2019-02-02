#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll q;
    ll n[310];
    string s[310];
    cin >> q;
    rep(i,0,q){
        cin >> n[i] >> s[i];
    }
    rep(i,0,q){
        if(n[i] == 2){
            if(s[i][0] - '0' >= s[i][1] - '0'){
                print("NO");
            }else{
                print("YES");
                print(2);
                cout << s[i][0] << " " << s[i][1] << endl;
            }
        }else{
            print("YES");
            print(2);
            cout << s[i][0] << " " << s[i].substr(1,n[i]-1) << endl;
        }
    }

}
