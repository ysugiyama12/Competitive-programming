#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
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
    ll x[100010];
    cin >> N >> K;
    rep(i,0,N){
        cin >> x[i];
    }
    ll ans = 1e12;
    rep(i,0,N-K+1){
        if(x[i] < 0 && x[i+K-1] < 0){
            ans = min(ans, abs(x[i]));
        }else if(x[i] > 0 && x[i+K-1] > 0){
            ans = min(ans, x[i+K-1]);
        }else{
            ll min_num = min(abs(x[i]), x[i+K-1]);
            ll max_num = max(abs(x[i]), x[i+K-1]);
            ll tt = min_num * 2 + max_num;
            ans = min(ans, tt);
        }
    }
    print(ans);
}
