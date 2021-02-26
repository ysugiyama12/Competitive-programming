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
    ll N,M,K;
    cin >> N >> M >> K;
    string s;
    cin >> s;
    ll a[100010], b[100010];
    vector<ll> tree[100010];
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    rep(i,0,M){
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    K %= 2;
    ll win_first[100010] = {};
    ll win_second[100010] = {};
    rep(i,0,N){
        bool is_win = false;
        for(auto &e : tree[i]){
            if(s[e] == 'B'){
                is_win = true;
            }
        }
        win_first[i] = (is_win) ? 0 : 1;
    }
    rep(i,0,N){
        bool is_win = false;
        for(auto &e : tree[i]){
            if(s[e] == 'R'){
                is_win = true;
            }
        }
        win_second[i] = (is_win) ? 1 : 0;
    }
    ll win_2[100010] = {};
    rep(i,0,N){
        bool is_win = false;
        for(auto &e : tree[i]){
            if(win_second[e] == 0){
                is_win = true;
            }
        }
        win_2[i] = (is_win) ? 0 : 1;
    }
    string ans[2] = {"First", "Second"};
    if(K % 2 == 1){
        rep(i,0,N){
            print(ans[win_first[i]]);
        }
    }else{
        rep(i,0,N){
            print(ans[win_2[i]]);
        }
    }

}
