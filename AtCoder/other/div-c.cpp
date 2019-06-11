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
    ll N;
    string s[10010];
    cin >> N;
    rep(i,0,N) cin >> s[i];
    ll tonari = 0, n_a = 0, n_b = 0, n_ab = 0;
    rep(i,0,N){
        rep(j,0,s[i].size()-1){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') tonari++;
        }
        if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') n_ab++;
        else if(s[i][0] == 'B') n_b++;
        else if(s[i][s[i].size()-1] == 'A') n_a++;
    }
    ll ans = tonari;
    if(n_ab > 0){
        if(n_a > 0){
            ans++;
            n_a--;
        }
        if(n_b > 0){
            ans++;
            n_b--;
        }
    }
    ll tt = min(n_a, n_b);
    ans += tt;
    if(n_ab > 0) ans += n_ab - 1;
    print(ans);

    // ll tt = min(n_a, n_b);
    // ans += tt;
    // // print(ans);
    // ll vv = max(n_a, n_b) - tt;
    // if(n_ab > 0){
    //     ans += n_ab - 1;
    //     if(vv > 0) ans++;
    // }
    // print(ans);

    
}