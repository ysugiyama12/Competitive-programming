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
    ll N;
    string s,t;
    cin >> N;
    cin >> s >> t;
    rep(i,0,N){
        string ss = s.substr(0,i) + t;
        if(ss.substr(0,N) == s && ss.substr(ss.size() - N, N) == t){
            print(ss.size());
            return 0;
        }
    }
    print(2*N);
    // ll pos = 0;
    // rep(i,0,N){
    //     if(s[N-1-i] == t[i]){
    //         pos++;
    //     }
    // }
    // rep(i,0,N-pos+1){
    //     cout << s[i];
    // }
    // rep(i,pos,N){
    //     cout << t[i];
    // }
    // cout << endl;
}
