#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,X,Y;
    int x[110], y[110];
    cin >> N >> M >> X >> Y;
    rep(i,0,N){
        cin >> x[i];
    }
    rep(i,0,M){
        cin >> y[i];
    }
    bool ans = false;
    rep(i,X+1,Y+1){
        bool is_war = false;
        rep(j,0,N){
            if(x[j] >= i){
                is_war = true;
            }
        }
        rep(j,0,M){
            if(y[j] < i){
                is_war = true;
            }
        }
        if(!is_war){
            ans = true;
        }
    }
    if(ans){
        print("No War");
    }else{
        print("War");
    }

}
