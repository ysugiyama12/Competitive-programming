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
    ll N;
    string S;
    cin >> N >> S;
    ll cnt = 0;
    ll max_cnt = 0;
    ll pos = -1;
    rep(i,0,N){
        if(S[i] == '>'){
            cnt++;
        }else{
            if(max_cnt < cnt){
                max_cnt = cnt;
                pos = i;
            }
            cnt = 0;
        }
    }
    if(max_cnt < cnt){
        max_cnt = cnt;
        pos = N;
    }
    double ans = 0;
    cnt = 0;
    rep(i,0,N){
        if(S[i] == '-'){
            ans += 1;
            cnt = 0;
        }else{
            ans += (double) 1/(cnt + 2);
            cnt++;
        }
    }
    // print(ans);
    // print(max_cnt);
    ans -= 1;
    ans += (double) 1/(max_cnt+2);
    cout << setprecision(10) << ans << endl;
}
