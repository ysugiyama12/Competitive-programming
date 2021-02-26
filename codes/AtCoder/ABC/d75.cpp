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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    ll x[55], y[55];
    cin >> N >> K;
    rep(i,0,N){
        cin >> x[i] >> y[i];
    }
    ll S = -1;
    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,N){
                rep(l,0,N){
                    if(x[i] > x[j] || y[k] < y[l]) continue;
                    int cnt = 0;
                    rep(m,0,N){
                        if(x[m] >= x[i] && x[m] <= x[j] && y[m] >= y[l] && y[m] <= y[k]){
                            cnt++;
                        }
                    }
                    if(cnt >= K){
                        ll s_tmp = (x[j] - x[i]) * (y[k] - y[l]);
                        if(S == -1){
                            S = s_tmp;
                        }else{
                            S = min(S, s_tmp);
                        }
                    }


                }
            }
        }
    }
    print(S);


}
