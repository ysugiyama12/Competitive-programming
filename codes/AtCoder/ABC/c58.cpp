#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
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
    int N;
    string S[55];
    cin >> N;
    rep(i,0,N){
        cin >> S[i];
    }
    int cnt[55][26] = {};
    rep(i,0,N){
        rep(j,0,S[i].size()){
            cnt[i][S[i][j] - 'a']++;
        }
    }
    rep(i,0,26){
        int min_cnt = 1e9;
        rep(j,0,N){
            min_cnt = min(min_cnt, cnt[j][i]);
        }
        if(min_cnt != 0){
            rep(j,0,min_cnt){
                cout << (char)('a'+i);
            }
        }
    }
    cout << endl;

}
