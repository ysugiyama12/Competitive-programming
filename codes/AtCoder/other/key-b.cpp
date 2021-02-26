#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    bool flg = false;
    if(S == "keyence") flg = true;
    rep(i,0,N){
        rep(j,0,N){
            string ss = "";
            ss += S.substr(0,i);
            if(j != N-1){
                ss += S.substr(j+1, N-j+1);
            }
            if(ss == "keyence") flg = true;
        }
    }
    if(flg){
        print("YES");
    }else{
        print("NO");
    }
    // ll idx = 0;
    // string str1 = "keyence";
    // rep(i,0,N){
    //     if(S[i] == str1[idx] && idx < 7){
    //         idx++;
    //     }
    // }
    // if(idx == 7){
    //     print("YES");
    // }else{
    //     print("NO");
    // }
}
