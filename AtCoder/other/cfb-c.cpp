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
    cin >> N;
    rep(i,0,N){
        rep(j,0,N){
            if((i == 0 && j == 0) || (i == 0 && j == N-1) || (i == N-1 && j == 0) || (i == N-1 && j == N-1)){
                cout << 'X';
            }else if((i == 0 && j % 3 == 0) || (i == N-1 && j%3 == 0) || (j == 0 && i%3 == 0) || (j == N-1 && i%3 == 0)){
                cout << 'X';
            }else if(i % 5 == 0){
                if(j % 5 == 0){
                    cout << 'X';
                }else{
                    cout << '.';
                }
            }else if(i % 5 == 1){
                if(j % 5 == 2){
                    cout << 'X';
                }else{
                    cout << '.';
                }
            }else if(i % 5 == 2){
                if(j % 5 == 4){
                    cout << 'X';
                }else{
                    cout << '.';
                }
            }else if(i % 5 == 3){
                if(j % 5 == 1){
                    cout << 'X';
                }else{
                    cout << '.';
                }
            }else{
                if(j % 5 == 3){
                    cout << 'X';
                }else{
                    cout << '.';
                }
            }
        }
        cout << endl;
    }
}
