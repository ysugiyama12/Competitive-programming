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
    string S;
    cin >> N >> S;
    rep(i,0,1<<2){
        char sw[100010];
        rep(j,0,2){
            if(i >> j & 1){
                sw[j] = 'S';
            }else{
                sw[j] = 'W';
            }
        }
        rep(j,1,N-1){
            if(S[j] == 'o' && sw[j] == 'S'){
                sw[j+1] = (sw[j-1] == 'S' ? 'S' : 'W');
            }else if(S[j] == 'o' && sw[j] == 'W'){
                sw[j+1] = (sw[j-1] == 'S' ? 'W' : 'S');
            }else if(S[j] == 'x' && sw[j] == 'S'){
                sw[j+1] = (sw[j-1] == 'S' ? 'W' : 'S');
            }else{
                sw[j+1] = (sw[j-1] == 'S' ? 'S' : 'W');
            }
        }
        int cnt = 0;
        if(S[N-1] == 'o' && sw[N-1] == 'S' && sw[N-2] == sw[0]){
            cnt++;
        }else if(S[N-1] == 'o' && sw[N-1] == 'W' && sw[N-2] != sw[0]){
            cnt++;
        }else if(S[N-1] == 'x' && sw[N-1] == 'S' && sw[N-2] != sw[0]){
            cnt++;
        }else if(S[N-1] == 'x' && sw[N-1] == 'W' && sw[N-2] == sw[0]){
            cnt++;
        }
        if(S[0] == 'o' && sw[0] == 'S' && sw[N-1] == sw[1]){
            cnt++;
        }else if(S[0] == 'o' && sw[0] == 'W' && sw[N-1] != sw[1]){
            cnt++;
        }else if(S[0] == 'x' && sw[0] == 'S' && sw[N-1] != sw[1]){
            cnt++;
        }else if(S[0] == 'x' && sw[0] == 'W' && sw[N-1] == sw[1]){
            cnt++;
        }
        if(cnt == 2){
            rep(i,0,N){
                cout << sw[i];
            }
            cout << endl;
            return 0;
        }


    }
    print(-1);
}
