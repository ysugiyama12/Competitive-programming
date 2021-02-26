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
    string s2 = S.substr(N,N);
    reverse(s2.begin(), s2.end());
    string ss = S.substr(0,N) + s2;
    map< pair<string, string>, ll> mp1, mp2;
    rep(bit,0,pow(2,N)){
        string sr = "", sb = "";
        rep(i,0,N){
            if((bit>>i) & 1){
                sr += ss[i];
            }else{
                sb += ss[i];
            }
        }
        mp1[make_pair(sr, sb)]++;
        mp1[make_pair(sb, sr)]++;
    }
    rep(bit,0,pow(2,N)){
        string sr = "", sb = "";
        rep(i,0,N){
            if((bit>>i) & 1){
                sr += ss[N+i];
            }else{
                sb += ss[N+i];
            }
        }
        mp2[make_pair(sr, sb)]++;
        mp2[make_pair(sb, sr)]++;
    }
    ll ans = 0;
    for(auto &e: mp1){
        ans += e.second * mp2[e.first];
    }
    print(ans/4);
}
