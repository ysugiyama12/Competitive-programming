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
    ll N;
    string s[110];
    cin >> N;
    rep(i,0,N) cin >> s[i];
    map<string,ll> mp;
    string prev = "";
    rep(i,0,N){
        if(mp[s[i]] != 0){
            if(i % 2 == 0){
                print("LOSE");
                return 0;
            }else{
                print("WIN");
                return 0;
            }
        }
        if(i != 0){
            if(s[i][0] != prev[prev.size()-1]){
                if(i % 2 == 0){
                    print("LOSE");
                    return 0;
                }else{
                    print("WIN");
                    return 0;
                }
            }
        }
        prev = s[i];
        mp[s[i]]++;
    }
    print("DRAW");
}
