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
    ll K;
    cin >> s;
    cin >> K;
    ll N = s.size();
    char ans[100010];
    rep(i,0,N){
        ans[i] = ' ';
    }
    bool short_flg = false;
    rep(i,0,N){
        if(s[i] == 'a'){
            ans[i] = 'a';
            continue;
        }
        ll diff_a = 'z' - s[i] + 1;
        if(diff_a <= K){
            K -= diff_a;
            ans[i] = 'a';
        }else{
            short_flg = true;
        }
    }
    rrep(i,N-1,0){
        if(ans[i] == ' '){
            ans[i] = s[i] + K;
            break;
        }
    }
    if(!short_flg){
        ans[N-1] = ans[N-1] + (K % 26);
    }
    rep(i,0,N){
        if(ans[i] == ' '){
            cout << s[i];
        }else{
            cout << ans[i];
        }
    }
    cout << endl;

}
