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
ll cc(char c){
    if(c == 'b'){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    ll vs = 0, vt = 0;
    ll ns = s.size();
    ll nt = t.size();
    rep(i,0,ns){
        vs += pow(2,ns-i-1) * cc(s[i]);
    }
    rep(i,0,nt){
        vt += pow(2,nt-i-1) * cc(t[i]);
    }
    ll sum = vs + vt;
    string ans = "";
    while(sum > 0){
        if(sum % 2 == 0){
            ans += 'b';
        }else{
            ans += 'B';
        }
        sum /= 2;
    }
    reverse(ans.begin(), ans.end());
    if(ans == ""){
        print('b');
    }else{
        print(ans);
    }
    

}
