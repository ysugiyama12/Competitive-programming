#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    ll cnt[26] = {};
    rep(i,0,N){
        cnt[S[i]-'a']++;
    }
    sort(cnt, cnt+26);
    ll v_odd = 0, v_even = 0;
    rep(i,0,26){
        if(cnt[i] == 0) continue;
        if(cnt[i] % 2 == 1){
            v_odd++;
        }else{
            v_even++;
        }
    }
    if(v_odd == 0){
        print(N);
        return 0;
    }else{
        ll num_div = v_odd;
        ll v = (N - num_div) / 2;
        ll ans = 1 + 2 * (v/num_div);
        print(ans);
        return 0;
    }
}
