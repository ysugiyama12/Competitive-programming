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
    ll N,M,L;
    string S[510];
    cin >> N >> M >> L;
    rep(i,0,N){
        cin >> S[i];
    }
    char board[30][30];
    rep(i,0,29){
        rep(j,0,29){
            if(i == 0 || i == 28){
                board[i][j] = '#';
            }else if(j == 0 || j == 28){
                board[i][j] = '#';
            }else{
                if(i == 1 || i == 27){
                    board[i][j] = 'L';
                }else if(j == 1 || j == 27){
                    board[i][j] = 'L';
                }else{
                    board[i][j] = 'R';
                    // ll num = rand() % 110;
                    // if(num == 0){
                    //     board[i][j] = 'D';
                    // }else{
                    //     board[i][j] = '.';
                    // }
                }
            }
        }
    }
    ll cnt[30][30] = {};
    rep(i,0,N){
        ll px = 14, py = 14;
        ll dd = 100000;
        rep(j,0,L){
            if(S[i][j] == 'S'){
                if(board[py][px] == '.' || board[py][px] == 'L' || board[py][px] == 'R'){
                    if(dd % 4 == 0){
                        if(py != 1) py--;
                    }
                    if(dd % 4 == 1){
                        if(px != 27) px++;
                    }
                    if(dd % 4 == 2){
                        if(py != 27) py++;
                    }
                    if(dd % 4 == 3){
                        if(px != 1) px--;
                    }
                }else if(board[py][px] == 'D'){
                    if(dd % 4 == 0){
                        if(py != 1) py--;
                        if(py != 1) py--;
                    }
                    if(dd % 4 == 1){
                        if(px != 27) px++;
                        if(px != 27) px++;
                    }
                    if(dd % 4 == 2){
                        if(py != 27) py++;
                        if(py != 27) py++;
                    }
                    if(dd % 4 == 3){
                        if(px != 1) px--;
                        if(px != 1) px--;
                    }
                }else if(board[py][px] == 'T'){
                    if(dd % 4 == 0){
                        if(py != 1) py--;
                        if(py != 1) py--;
                        if(py != 1) py--;
                    }
                    if(dd % 4 == 1){
                        if(px != 27) px++;
                        if(px != 27) px++;
                        if(px != 27) px++;
                    }
                    if(dd % 4 == 2){
                        if(py != 27) py++;
                        if(py != 27) py++;
                        if(py != 27) py++;
                    }
                    if(dd % 4 == 3){
                        if(px != 1) px--;
                        if(px != 1) px--;
                        if(px != 1) px--;
                    }
                }
            }else if(S[i][j] == 'L'){
                if(board[py][px] == '.' || board[py][px] == 'L'){
                    dd--;
                }else if(board[py][px] == 'D'){
                    dd -= 2;
                }else if(board[py][px] == 'T'){
                    dd -= 3;
                }else if(board[py][px] == 'R'){
                    dd++;
                }
            }else{
                if(board[py][px] == '.' || board[py][px] == 'R'){
                    dd++;
                }else if(board[py][px] == 'D'){
                    dd += 2;
                }else if(board[py][px] == 'T'){
                    dd += 3;
                }else if(board[py][px] == 'L'){
                    dd--;
                }
            }
        }
        cnt[py][px]++;

    }
    printa2(cnt,29,29);
    ll ans = 0;
    rep(i,0,29){
        rep(j,0,29){
            if(cnt[i][j] == 1){
                ans += 10;
            }else if(cnt[i][j] == 2){
                ans += 3;
            }else if(cnt[i][j] == 3){
                ans += 1;
            }
        }
    }
    rep(i,0,29){
        rep(j,0,29){
            cout << board[i][j];
        }
        cout << endl;
    }

    print(ans);
}
