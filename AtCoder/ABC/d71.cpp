
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
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;
    ll mod = 1e9 + 7;
    ll ans = 0;
    if(S1[0] == S2[0]){
        ans += 3;
    }else{
        ans += 6;
    }
    rep(i,1,N){
        if(S1[i-1] == S2[i-1] && S1[i] == S2[i]){
            ans *= 2;
        }else if(S1[i-1] == S2[i-1] && S1[i] != S2[i]){
            ans *= 2;
        }else if(S1[i-1] != S2[i-1] && S1[i] != S2[i]){
            if(S1[i-1] != S1[i]){
                ans *= 3;
            }
        }else if(S1[i-1] != S2[i-1] && S1[i] == S2[i]){
            ans *= 1;
        }
        ans %= mod;

    }
    print(ans);


}
