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
    int N;
    cin >> N;
    int C[510], S[510], F[510];
    rep(i,0,N-1){
        cin >> C[i] >> S[i] >> F[i];
    }
    rep(i,0,N){
        ll ans = 0;
        if(i == N-1){
            print("0");
            continue;
        }
        rep(j,i,N-1){
            if(j == i){
                ans += S[j] + C[j];
            }else{
                if(ans < S[j]){
                    ans += S[j] - ans;
                }else{
                    int tt = (ans - S[j]) % F[j];
                    if(tt != 0){
                        ans += F[j] - tt; 
                    }
                }
                ans += C[j];
            }
        }
        print(ans);
    }

}
