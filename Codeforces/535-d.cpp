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
    string S;
    cin >> N >> S;
    ll cnt = 0;
    map<ll,ll> mp;
    rep(i,1,N){
        if(S[i-1] == S[i]){
            cnt++;
        }else{
            cnt = 0;
        }
        if(cnt % 2 == 1){
            mp[i] = 1;
        }
    }
    ll v = 0;
    string ans = "";
    rep(i,0,N){
        if(mp[i] == 0){
            ans += S[i];
        }else{
            v++;
            if(i != N-1){
                if(S[i] != 'R' && S[i+1] != 'R'){
                    ans += "R";
                }else if(S[i] != 'G' && S[i+1] != 'G'){
                    ans += "G";
                }else{
                    ans += "B";
                }
            }else{
                if(S[i] != 'R'){
                    ans += "R";
                }else if(S[i] != 'G'){
                    ans += "G";
                }else{
                    ans += "B";
                }
            }
        }
    }
    print(v);
    print(ans);
}
