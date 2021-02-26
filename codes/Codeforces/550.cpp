#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    string S,T;
    cin >> S >> T;
    string tt = "";
    ll kuri = 0;
    rrep(i,K-1,0){
        ll v1 = S[i]-'a'+1 + T[i] - 'a'+1 + kuri;
        if(v1 <= 26){
            kuri = 0;
            tt += 'a' + v1 - 1;
        }else{
            if(v1 == 27){
                tt += 'a';
                kuri = 1;
            }else{
                kuri = 1;
                tt += 'a' + (v1 - 28);
            }
        }
    }
    if(kuri == 1){
        tt += 'a';
    }
    reverse(tt.begin(), tt.end());
    ll nt = tt.size();
    rrep(i,nt-1,0){
        if(tt[i] != 'z'){
            tt[i] = tt[i]+1;
            break;
        }else{
            tt[i] = 'a';
        }
    }
    print(tt);
    string ans = "";
    ll keta = 0;
    rep(i,0,nt){
        ll v = keta * 27 + tt[i] - 'a' + 1;
        if(v % 2 == 0){
            keta = 0;
            ans += 'a' + v/2 - 1;
        }else{
            keta = 1;
            if(v != 1) ans += 'a' + (v-1)/2 - 1;
        }
    }
    print(ans);
    


}