#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
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
    ll ans = 0;
    ll w_cnt = 0;
    rep(i,0,N){
        if(S[i] == 'W'){
            w_cnt++;
        }
    }
    vector<ll> mv;
    rep(i,0,w_cnt){
        if(S[i] == 'B'){
            mv.push_back(i);
        }
    }
    // print(mv.size());
    ll mv_num = w_cnt - mv.size();
    // print(mv_num);
    ll cnt = 0;
    ll idx = 0;
    rep(i,0,N){
        if(S[i] == 'W'){
            cnt++;
        }
        if(cnt > mv_num && S[i] == 'W'){
            // print(idx);
            ans += (i - mv[idx]);
            idx++;
        }
    }
    print(ans);

}
