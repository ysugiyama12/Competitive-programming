#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;
ll a_tmp[310][310] = {};
ll b_tmp[310][310] = {};
ll A[310][310] = {};
int N;
void floyd(){
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                a_tmp[i][j] = min(a_tmp[i][j], a_tmp[i][k] + a_tmp[k][j]);
            }
        }
    }
}
void floyd2(){
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                if(A[i][j] == A[i][k] + A[k][j] && i != j && j != k && k != i){
                    b_tmp[i][j] = 1;
                }
            }
        }
    }
    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N){
        rep(j,0,N){
            cin >> A[i][j];
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            a_tmp[i][j] = A[i][j];
        }
    }
    floyd();
    bool flg = true;
    rep(i,0,N){
        rep(j,0,N){
            if(A[i][j] != a_tmp[i][j]){
                flg = false;
            }
        }
    }
    if(!flg){
        print("-1");
        return 0;
    }
    floyd2();
    ll ans = 0;
    rep(i,0,N){
        rep(j,0,N){
            if(b_tmp[i][j] == 0){
                ans += A[i][j];
            }
        }
    }
    ans /= 2;
    print(ans);



}
