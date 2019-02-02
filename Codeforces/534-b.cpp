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
    string s;
    cin >> s;
    ll n = s.size();
    stack<ll> ss;
    ss.push(s[0]);
    ll cnt = 0;
    rep(i,1,n){
        if(ss.empty()){
            ss.push(s[i]);
            continue;
        }
        ll s1 = ss.top();
        if(s[i] == s1){
            cnt++;
            ss.pop();
        }else{
            ss.push(s[i]);
        }
    }
    if(cnt % 2 == 0){
        print("NO");
    }else{
        print("YES");
    }
    // ll cnt = 0;
    // bool skip = false;
    // rep(i,1,n){
    //     if(skip){
    //         skip = false;
    //         continue;
    //     }
    //     if(s[i] == s[i-1]){
    //         cnt++;
    //         skip = true;
    //     }
    // }
    // if(cnt % 2 == 0){
    //     print("NO");
    // }else{
    //     print("YES");
    // }
}
