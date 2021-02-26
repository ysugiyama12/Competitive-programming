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
bool cc(char c){
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    if(s.size() != t.size()){
        print("No");
        return 0;
    }
    ll N = s.size();
    char c[5] = {'a','i','u','e','o'};
    bool ok = true;
    rep(i,0,N){
        bool flg = cc(s[i]);
        if(flg){
            bool flg2 = cc(t[i]);
            if(!flg2) ok = false;
        }else{
            bool flg3 = cc(t[i]);
            if(flg3){
                ok = false;
            }
        }
    }
    if(ok){
        print("Yes");
    }else{
        print("No");
    }
}
